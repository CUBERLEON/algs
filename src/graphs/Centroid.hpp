/* Centroid of a tree
 * Complexity: N
 * Input: g {tree} */
constexpr int MAX = 100010;

int s[MAX], used[MAX];

int find_centroid(const vector<vector<int>>& g, int v = 0)
{
    int n = g.size();

    used[v] = 1;
    s[v] = 1;
    bool centroid = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to]) continue;

        int t = find_centroid(g, to);
        if (t != -1) return t;

        s[v] += s[to];
        centroid &= s[to] <= n/2;
    }
    centroid &= n-s[v] <= n/2;

    return (centroid ? v : -1);
}
