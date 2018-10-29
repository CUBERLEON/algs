#include <catch.hpp>

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

namespace
{
    #include <graphs/CentroidDecomposition.hpp>

    void add_edge(vector<vector<int>>& g, int v1, int v2)
    {
    	g[v1].push_back(v2);
    	g[v2].push_back(v1);
    }

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
