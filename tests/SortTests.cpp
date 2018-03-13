#include <catch.hpp>
#include <bits/stdc++.h>

#include <Sort.hpp>

#define TEST_SORT(type) \
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

    SECTION("Bubble sort")    { TEST_SORT(Sort::BubbleSort); }
    SECTION("Selection sort") { TEST_SORT(Sort::SelectionSort); }
    SECTION("Insertion sort") { TEST_SORT(Sort::InsertionSort); }
    SECTION("Merge sort")     { TEST_SORT(Sort::MergeSort); }
    SECTION("Quick sort")     { TEST_SORT(Sort::QuickSort); }
    SECTION("Radix sort")     { TEST_SORT(Sort::RadixSort); }
    SECTION("Heap sort")      { TEST_SORT(Sort::HeapSort); }
}
