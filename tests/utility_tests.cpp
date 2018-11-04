#include <catch.hpp>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

namespace Invertions
{
    #include <utility/Invertions.hpp>

    TEST_CASE("Invertions")
    {
        int a1[] = {9, 1, 8, 5, 2, 7, 4, 3, 10, 6};
        REQUIRE(count_invertions(a1, 10) == 22);

        int a2[] = {9, 1, 8};
        REQUIRE(count_invertions(a2, 3) == 2);
    }
}

namespace Long_arithmetic
{
    #include <utility/Long_arithmetic.hpp>

    TEST_CASE("Long integer arithmetic")
    {
        SECTION("Creation and to string conversion")
        {
            REQUIRE(create(123456789) == vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 });
            REQUIRE(create("123456789") == vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 });
            REQUIRE(to_string(create(123456789)) == "123456789");
            REQUIRE(to_string(create("45324907523940572345")) == "45324907523940572345");
        }

        SECTION("Multiplication")
        {
            REQUIRE(to_string(multiply(create("826345634645634653459123"), 23452372)) == "19379765224285512069014439389756");
            REQUIRE(to_string(multiply(create(82634563), 0)) == "0");
            REQUIRE(to_string(multiply(create(0), 82634563)) == "0");
        }

        SECTION("Subtraction")
        {
            REQUIRE(to_string(subtract(create(3486534), create(3486534))) == "0");
            REQUIRE(to_string(subtract(create(534658293), create(2131425))) == "532526868");
        }
    }
}

#define test_sort(type) \
{ \
    copy = orig; \
    type(copy.data(), N); \
    REQUIRE(copy == target); \
} \

namespace Sort
{
    #include <utility/Sort.hpp>

    TEST_CASE("Sort")
    {
        const int N = 1000;
        
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