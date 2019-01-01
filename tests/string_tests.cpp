#include <catch.hpp>
#include <vector>
#include <string>
using namespace std;

namespace KMP
{
    #include <string/KMP.hpp>

    string gen_letters(int len, int k)
    {
        string res(len, ' ');
        for (int i = 0; i < len; ++i) res[i] = 'a' + rand() % k;
        return res;
    }

    TEST_CASE("Prefix function")
    {
        string s = "abcabcd";
        vector<int> expected = { 0, 0, 0, 1, 2, 3, 0 };

        REQUIRE(prefix_values(s) == expected);
    }

    vector<int> brute_substring_search(const string& needle, const string& text)
    {
        vector<int> res;

        for (int i = 0; i + needle.size() <= text.size(); ++i)
        {
            bool match = true;
            for (int j = 0; j < needle.size(); ++j)
            {
                if (text[i+j] != needle[j])
                {
                    match = false;
                    break;
                }
            }
            if (match) res.push_back(i);
        }

        return res;
    }

    TEST_CASE("KMP")
    {
        srand(time(0));

        string text = "Afrghdg dtg dtg dtg srghr!";
        string needle = "dtg";
        vector<int> expected = { 8, 12, 16 };

        string text_1 = gen_letters(10000, 10);
        string text_2 = gen_letters(100000, 10);
        string text_3 = gen_letters(1000000, 5);
        string needle_1 = gen_letters(2, 10);
        string needle_2 = gen_letters(3, 10);
        string needle_3 = gen_letters(7, 5);

        SECTION("KMP 1")
        {
            REQUIRE(kmp_1(needle, text) == expected);
            REQUIRE(kmp_1(needle_1, text_1) == brute_substring_search(needle_1, text_1));
            REQUIRE(kmp_1(needle_2, text_2) == brute_substring_search(needle_2, text_2));
            REQUIRE(kmp_1(needle_3, text_3) == brute_substring_search(needle_3, text_3));
        }

        SECTION("KMP 2")
        {
            REQUIRE(kmp_2(needle, text) == expected);
            REQUIRE(kmp_2(needle_1, text_1) == brute_substring_search(needle_1, text_1));
            REQUIRE(kmp_2(needle_2, text_2) == brute_substring_search(needle_2, text_2));
            REQUIRE(kmp_2(needle_3, text_3) == brute_substring_search(needle_3, text_3));
        }
    }
}
