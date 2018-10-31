#include <catch.hpp>

#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define test_sort(type) \
{ \
    copy = orig; \
    type(copy.data(), N); \
    REQUIRE(copy == target); \
} \

namespace
{
    #include <utility/Sort.hpp>

    const int N = 200;

    TEST_CASE("Sort")
    {
        vector<int> orig(N), copy, target;
        generate(orig.begin(), orig.end(), rand);
        target = orig;
        sort(target.begin(), target.end());

        SECTION("Bubble sort")    { test_sort(bubble_sort); }
        SECTION("Selection sort") { test_sort(selection_sort); }
        SECTION("Insertion sort") { test_sort(insertion_sort); }
        SECTION("Merge sort")     { test_sort(merge_sort); }
        SECTION("Quick sort")     { test_sort(quick_sort); }
        SECTION("Radix sort")     { test_sort(radix_sort); }
        SECTION("Heap sort")      { test_sort(heap_sort); }
    }
}
