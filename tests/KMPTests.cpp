#include <catch.hpp>

#include <vector>
#include <string>
using namespace std;

namespace
{
    #include <KMP.hpp>

    TEST_CASE("Prefix function")
    {
        string s = "abcabcd";
        vector<int> expected = { 0, 0, 0, 1, 2, 3, 0 };

        REQUIRE(PrefixValues(s) == expected);
    }

    TEST_CASE("KMP")
    {
        string text = "Afrghdg dtg dtg dtg srghr!";
        string needle = "dtg";
        vector<int> expected = { 8, 12, 16 };

        SECTION("KMP 1")
        {
            REQUIRE(KMP1(needle, text) == expected);
        }

        SECTION("KMP 2")
        {
            REQUIRE(KMP2(needle, text) == expected);
        }
    }
}
