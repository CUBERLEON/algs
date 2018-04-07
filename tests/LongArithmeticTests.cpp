#include <catch.hpp>

#include <vector>
#include <string>
using namespace std;

namespace
{
    #include <LongArithmetic.hpp>

    TEST_CASE("Long integer arithmetic")
    {
        SECTION("Creation & ToString")
        {
            REQUIRE(Create(123456789) == vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 });
            REQUIRE(Create("123456789") == vector<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 });
            REQUIRE(ToString(Create(123456789)) == "123456789");
            REQUIRE(ToString(Create("45324907523940572345")) == "45324907523940572345");
        }

        SECTION("Multiplication")
        {
            REQUIRE(ToString(Multiply(Create("826345634645634653459123"), 23452372)) == "19379765224285512069014439389756");
            REQUIRE(ToString(Multiply(Create(82634563), 0)) == "0");
            REQUIRE(ToString(Multiply(Create(0), 82634563)) == "0");
        }

        SECTION("Subtraction")
        {
            REQUIRE(ToString(Subtract(Create(3486534), Create(3486534))) == "0");
            REQUIRE(ToString(Subtract(Create(534658293), Create(2131425))) == "532526868");
        }
    }
}
