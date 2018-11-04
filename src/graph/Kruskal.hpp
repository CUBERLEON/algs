/* Given an undirected graph finds its minimal spanning tree
 * Uses disjoint-set data structure
 * Complexity: O(E) - time, O(V) - space
 */
struct Edge
{
    int a, b, weight;

    bool operator< (const Edge& r)
    {
        return weight < r.weight;
    }
};

vector<Edge> kruskal(vector<Edge>& edges, int n)
{
    vector<Edge> result;

    vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge& edge : edges)
    {
        if (unite(parent, edge.a, edge.b))
        {
            result.push_back(edge);
        }
    }

    return result;
}