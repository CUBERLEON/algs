#include <catch.hpp>

#include <vector>
#include <set>
using namespace std;

namespace
{
    #include <graphs/Dijkstra.hpp>

    TEST_CASE("Dijkstra")
    {
        constexpr size_t n = 8;

        vector<vector<Edge>> g(n);
        g[0] = { {3, 2} };
        g[1] = { {3, 5} };
        g[2] = { {3, 5} };
        g[3] = { {0, 2}, {1, 2}, {4, 1}, {2, 100} };
        g[4] = { {3, 3}, {5, 11} };
        g[5] = { {6, 6}, {2, 2} };
        g[6] = { };
        g[7] = { {5, 1} };

        int inf = numeric_limits<int>::max();

        REQUIRE(dijkstra(g, 0) == vector<int>{ 0, 4, 16, 2, 3, 14, 20, inf });
        REQUIRE(dijkstra(g, 1) == vector<int>{ 7, 0, 19, 5, 6, 17, 23, inf });
        REQUIRE(dijkstra(g, 3) == vector<int>{ 2, 2, 14, 0, 1, 12, 18, inf });
        REQUIRE(dijkstra(g, 6) == vector<int>{ inf, inf, inf, inf, inf, inf, 0, inf });
        REQUIRE(dijkstra(g, 7) == vector<int>{ 10, 10, 3, 8, 9, 1, 7, 0 });
    }
}
