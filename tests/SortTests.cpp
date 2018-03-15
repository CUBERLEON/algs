#include <catch.hpp>

#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define TestSort(type) \
{ \
    copy = orig; \
    type(copy.data(), N); \
    REQUIRE(copy == target); \
} \

namespace
{
    #include <Sort.hpp>

    const int N = 200;

    TEST_CASE("Sort")
    {
        vector<int> orig(N), copy, target;
        generate(orig.begin(), orig.end(), rand);
        target = orig;
        sort(target.begin(), target.end());

        SECTION("Bubble sort")    { TestSort(BubbleSort); }
        SECTION("Selection sort") { TestSort(SelectionSort); }
        SECTION("Insertion sort") { TestSort(InsertionSort); }
        SECTION("Merge sort")     { TestSort(MergeSort); }
        SECTION("Quick sort")     { TestSort(QuickSort); }
        SECTION("Radix sort")     { TestSort(RadixSort); }
        SECTION("Heap sort")      { TestSort(HeapSort); }
    }
}
