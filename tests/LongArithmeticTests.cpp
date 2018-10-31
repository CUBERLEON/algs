#include <catch.hpp>

#include <vector>
#include <string>
using namespace std;

namespace
{
    #include <utility/LongArithmetic.hpp>

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
