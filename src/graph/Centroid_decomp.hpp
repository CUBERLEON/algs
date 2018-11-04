/* Centroid decomposition of a tree
 * Complexity: V*Log(V)
 * Input: g {tree}; Output: dg {rooted tree}
 */
constexpr int MAX = 100010;

int s[MAX];
bool used[MAX], is_centroid[MAX];

int find_centroid(const vector<vector<int>>& g, int n, int v = 0)
{
    used[v] = true;
    s[v] = 1;
    bool centroid = true;

    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (used[to] || is_centroid[to]) continue;

        int t = find_centroid(g, n, to);
        if (t != -1) return t;

        s[v] += s[to];
        centroid &= s[to] <= n/2;
    }
    centroid &= n-s[v] <= n/2;

    return (centroid ? v : -1);
}

int count_vertices(const vector<vector<int>>& g, int v) {
    int ans = 1;
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (used[to] || is_centroid[to]) continue;
        ans += count_vertices(g, to);
    }
    return ans;
}

int decompose(const vector<vector<int>>& g, vector<vector<int>>& dg, int start = 0)
{
    memset(used, 0, sizeof used);
    int cnt = count_vertices(g, start);

    memset(used, 0, sizeof used);
    int v = find_centroid(g, cnt, start);
    is_centroid[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!is_centroid[to])
        {
            int sub_v = decompose(g, dg, to);

            dg[v].push_back(sub_v);
            dg[sub_v].push_back(v);
        }
    }

    return v;
}
