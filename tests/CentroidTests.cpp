#include <catch.hpp>
#include <bits/stdc++.h>

#include <Centroid.hpp>

TEST_CASE("Centroid")
{
    constexpr int n = 8;

    std::vector<std::vector<int>> g(n);
    g[4] = { 3, 5 };
    g[3] = { 4, 0, 1, 2 };
    g[5] = { 4, 6, 7 };
    g[0] = { 3 };
    g[1] = { 3 };
    g[2] = { 3 };
    g[6] = { 5 };
    g[7] = { 5 };

    REQUIRE(Centroid::FindCentroid(g) == 4);
}
