#include <catch.hpp>

#include <vector>
#include <algorithm>
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

namespace
{
    #include <data_structures/Sqrt_decomp.hpp>

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
