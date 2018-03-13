#include <catch.hpp>
#include <bits/stdc++.h>

#include <Invertions.hpp>

TEST_CASE("Invertions")
{
    int a1[] = {9, 1, 8, 5, 2, 7, 4, 3, 10, 6};
    REQUIRE(Invertions::CountInvertions(a1, 10) == 22);

    int a2[] = {9, 1, 8};
    REQUIRE(Invertions::CountInvertions(a2, 3) == 2);
}
