/* Breadth first search graph traversal
 * Complexity: O(V+E) - time, O(V) - space
 */
constexpr int MAX = 10000;

int visited[MAX];

void bfs(vector<vector<int>>& g, int origin)
{
    queue<int> q;
    visited[origin] = true;
    q.push(origin);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < g[cur].size(); ++i)
        {
            int to = g[cur][i];
            if (visited[to]) continue;

            visited[to] = true;
            q.push(to);
        }
    }
}