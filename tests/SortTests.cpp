#include <catch.hpp>
#include <vector>

#include <Sort.hpp>

#define TestSort(type) \
{ \
    copy = orig; \
    type(copy.data(), N); \
    REQUIRE(copy == target); \
} \

const int N = 200;

TEST_CASE("Sort")
{
    std::vector<int> orig(N), copy, target;
    std::generate(orig.begin(), orig.end(), std::rand);
    target = orig;
    std::sort(target.begin(), target.end());

    SECTION("Bubble sort")    { TestSort(Sort::BubbleSort); }
    SECTION("Selection sort") { TestSort(Sort::SelectionSort); }
    SECTION("Insertion sort") { TestSort(Sort::InsertionSort); }
    SECTION("Merge sort")     { TestSort(Sort::MergeSort); }
    SECTION("Quick sort")     { TestSort(Sort::QuickSort); }
    SECTION("Radix sort")     { TestSort(Sort::RadixSort); }
    SECTION("Heap sort")      { TestSort(Sort::HeapSort); }
}
