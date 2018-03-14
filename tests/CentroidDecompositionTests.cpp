#include <catch.hpp>
#include <iostream>

#include <CentroidDecomposition.hpp>

void AddEdge(std::vector<std::vector<int>>& g, int v1, int v2)
{
	g[v1].push_back(v2);
	g[v2].push_back(v1);
}

TEST_CASE("Centroid decomposition")
{
    constexpr size_t n = 16;

	std::vector<std::vector<int>> g(n), dg(n);
	AddEdge(g, 0, 3);
	AddEdge(g, 1, 3);
	AddEdge(g, 2, 3);
	AddEdge(g, 3, 4);
	AddEdge(g, 4, 5);
	AddEdge(g, 5, 6);
	AddEdge(g, 6, 7);
	AddEdge(g, 6, 8);
	AddEdge(g, 5, 9);
	AddEdge(g, 9, 10);
	AddEdge(g, 10, 11);
	AddEdge(g, 10, 12);
	AddEdge(g, 11, 13);
	AddEdge(g, 12, 14);
	AddEdge(g, 12, 15);

    int root = CentroidDecomposition::Decompose(g, dg);
    REQUIRE(root == 5);

    // TODO: add test cases
    // for (size_t i = 0; i < n; ++i)
    // {
    //     std::cout << i << ":";
    //     for (size_t j = 0; j < dg[i].size(); ++j)
    //         std::cout << " " << dg[i][j];
    //     std::cout << std::endl;
    // }
}
