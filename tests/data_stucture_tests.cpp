#include <catch.hpp>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

int sum(const vector<int>& a, size_t left, size_t right)
{
    int result = 0;
    for (size_t i = left; i <= right; ++i)
    {
        result += a[i];
    }
    return result;
}

pair<size_t, size_t> gen_range(size_t n)
{
    size_t left = rand() % n;
    size_t right = rand() % n;
    if (left > right) swap(left, right);
    return { left, right };
}

namespace Disjoint_set
{
    #include <data_structure/Disjoint_set.hpp>
}

namespace Sqrt_decomp
{
    #include <data_structure/Sqrt_decomp.hpp>

    TEST_CASE("Sqrt decomposition")
    {
        srand(time(NULL));

        SECTION("Small input data")
        {
            Sqrt_sum a1(20);

            a1.add_on_range(0, 4, 1);
            a1.add_on_range(2, 4, 2);
            a1.add_on_range(1, 3, 3);
            a1.add_on_range(0, 3, 2);
            REQUIRE(a1.sum(0, 4) == 28);
            REQUIRE(a1.sum(0, 0) == 3);
        }

        constexpr int n = 100;
        constexpr int num_queries = 100;
        constexpr int mod = 100;

        Sqrt_sum a_sqrt(n);
        vector<int> a(n);

        SECTION("Add on range")
        {
            for (int i = 0; i < num_queries; ++i)
            {
                int add_value = rand() % mod;

                auto range1 = gen_range(n);
                a_sqrt.add_on_range(range1.first, range1.second, add_value);

                for (int j = range1.first; j <= range1.second; ++j)
                {
                    a[j] += add_value;
                }

                auto range2 = gen_range(n);
                REQUIRE(a_sqrt.sum(range2.first, range2.second) == sum(a, range2.first, range2.second));
            }
        }

        SECTION("Assignment")
        {
            for (int i = 0; i < num_queries; ++i)
            {
                size_t index = rand() % n;
                int value = rand() % mod;

                a_sqrt.assign(index, value);

                a[index] = value;

                auto range = gen_range(n);
                REQUIRE(a_sqrt.sum(range.first, range.second) == sum(a, range.first, range.second));
            }
        }
    }
}

namespace Trie
{
    #include <data_structure/Trie.hpp>

    TEST_CASE("Trie")
    {
        Trie trie;

        trie.insert("abcdefghabc");
        trie.insert("qwertyuio");
        trie.insert("asdfghjkl");
        trie.insert("zxcvbn");
        trie.insert("atest");
        trie.insert("btest");
        trie.insert("ctest");

        SECTION("Search word")
        {
            REQUIRE(trie.search("btest") == true);
            REQUIRE(trie.search("asdfghjkl") == true);
            REQUIRE(trie.search("abcdefgh") == false);
            
            REQUIRE(trie.search("test") == false);
            trie.insert("test");
            REQUIRE(trie.search("test") == true);
            
            REQUIRE(trie.search("") == false);
            trie.insert("");
            REQUIRE(trie.search("") == true);
        }

        SECTION("Search prefix")
        {
            REQUIRE(trie.search_prefix("abc") == true);
            REQUIRE(trie.search_prefix("atest") == true);
            REQUIRE(trie.search_prefix("") == true);
            
            REQUIRE(trie.search_prefix("d") == false);
            trie.insert("dtest");
            REQUIRE(trie.search_prefix("d") == true);
        }
    }
}