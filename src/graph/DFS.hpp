/* Depth first search graph traversal
 * Complexity: O(N+M) - time, O(N) - space
 */
constexpr int MAX = 10000;

int visited[MAX];

void dfs(vector<vector<int>>& g, int v)
{
    visited[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (visited[to]) continue;

        dfs(g, to);
    }
}