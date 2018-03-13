/* Centroid decomposition of a tree
 * Complexity: N*logN
 * Input: g {tree}; Output: dg {rooted tree} */
#include <bits/stdc++.h>

namespace CentroidDecomposition
{
    using namespace std;

    constexpr int MAX = 100010;

    int s[MAX], used[MAX], is_centroid[MAX];

    int FindCentroid(const vector<vector<int>>& g, int v = 0)
    {
        int n = g.size();

        used[v] = 1;
        s[v] = 1;
        bool centroid = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (used[to]) continue;

            int t = FindCentroid(g, to);
            if (t != -1) return t;

            s[v] += s[to];
            centroid &= s[to] <= n/2;
        }
        centroid &= n-s[v] <= n/2;

        return (centroid ? v : -1);
    }

    int CountVertices(const vector<vector<int>>& g, int v) {
        int ans = 1;
        used[v] = 1;
        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (used[to] || is_centroid[to]) continue;
            ans += CountVertices(g, to);
        }
        return ans;
    }

    int Decompose(const vector<vector<int>>& g, vector<vector<int>>& dg, int start = 0)
    {
        memset(used, 0, sizeof used);
        int cnt = CountVertices(g, start);

        memset(used, 0, sizeof used);
        int v = FindCentroid(g, start);
        is_centroid[v] = 1;

        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (!is_centroid[to])
            {
                int sub_v = Decompose(g, dg, to);

                dg[v].push_back(sub_v);
                dg[sub_v].push_back(v);
            }
        }

        return v;
    }
}
