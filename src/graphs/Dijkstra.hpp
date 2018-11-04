/* Finds shortest distance from an origin vertex to all other vertices.
 * This implementation uses `set` to get the vertex with smallest distance at each iteration of the algorithm.
 * Complexity: O(M*Log(N)) - time, O(N) - space, where M - # of edges, N - # of vertices
 */
 
struct Edge
{
    int vert;
    int dist;
};

vector<int> dijkstra(const vector<vector<Edge>>& g, int origin)
{
    int n = g.size();

    vector<bool> found_dist(n, false);
    vector<int> best_dist(n, numeric_limits<int>::max());
    set<pair<int, int>> q;

    q.insert({0, origin});
    best_dist[origin] = 0;

    while (!q.empty())
    {
        int cur = q.begin()->second;
        q.erase(q.begin());

        found_dist[cur] = true;

        for (int i = 0; i < g[cur].size(); ++i)
        {
            int to = g[cur][i].vert;
            if (found_dist[to]) continue;
            
            int new_dist = best_dist[cur] + g[cur][i].dist;
            if (new_dist < best_dist[to])
            {
                auto it = q.find({best_dist[to], to});
                if (it != q.end()) q.erase(it);

                best_dist[to] = new_dist;

                q.insert({best_dist[to], to});
            }
        }
    }

    return best_dist;
}