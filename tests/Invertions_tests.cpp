#include <catch.hpp>

#include <cstring>
using namespace std;

namespace
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
