#include <catch.hpp>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

void add_edge(vector<vector<int>>& g, int v1, int v2)
{
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

namespace BFS
{
    #include <graph/BFS.hpp>
}

namespace Centroid_decomp
{
    #include <graph/Centroid_decomp.hpp>

    TEST_CASE("Centroid decomposition")
    {
        constexpr size_t n = 16;

    	vector<vector<int>> g(n), dg(n);
    	add_edge(g, 0, 3);
    	add_edge(g, 1, 3);
    	add_edge(g, 2, 3);
    	add_edge(g, 3, 4);
    	add_edge(g, 4, 5);
    	add_edge(g, 5, 6);
    	add_edge(g, 6, 7);
    	add_edge(g, 6, 8);
    	add_edge(g, 5, 9);
    	add_edge(g, 9, 10);
    	add_edge(g, 10, 11);
    	add_edge(g, 10, 12);
    	add_edge(g, 11, 13);
    	add_edge(g, 12, 14);
    	add_edge(g, 12, 15);

        int root = decompose(g, dg);
        REQUIRE(root == 5);

        // TODO: add test cases
        // for (size_t i = 0; i < n; ++i)
        // {
        //     cout << i << ":";
        //     for (size_t j = 0; j < dg[i].size(); ++j)
        //         cout << " " << dg[i][j];
        //     cout << endl;
        // }
    }
}

namespace Centroid
{
    #include <graph/Centroid.hpp>

    TEST_CASE("Centroid")
    {
        constexpr size_t n = 8;

        vector<vector<int>> g(n);
        g[0] = { 3 };
        g[1] = { 3 };
        g[2] = { 3 };
        g[3] = { 0, 1, 2, 4 };
        g[4] = { 3, 5 };
        g[5] = { 4, 6, 7 };
        g[6] = { 5 };
        g[7] = { 5 };

        REQUIRE(find_centroid(g) == 4);
    }
}

namespace DFS
{
    #include <graph/DFS.hpp>
}

namespace Dijkstra
{
    #include <graph/Dijkstra.hpp>

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

namespace Kruskal
{
    #include <data_structure/Disjoint_set.hpp>
    #include <graph/Kruskal.hpp>
}