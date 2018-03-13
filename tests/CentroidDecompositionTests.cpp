#include <catch.hpp>
#include <bits/stdc++.h>

#include <CentroidDecomposition.hpp>

TEST_CASE("Centroid decomposition")
{
    constexpr int n = 8;

    std::vector<std::vector<int>> g(n), dg(n);
    g[4] = { 3, 5 };
    g[3] = { 4, 0, 1, 2 };
    g[5] = { 4, 6, 7 };
    g[0] = { 3 };
    g[1] = { 3 };
    g[2] = { 3 };
    g[6] = { 5 };
    g[7] = { 5 };

    int root = CentroidDecomposition::Decompose(g, dg);
    REQUIRE(root == 4);

    // TODO: add test cases
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < dg[i].size(); ++j)
            if (i < dg[i][j]) std::cout << i << " " << dg[i][j] << std::endl;
}
