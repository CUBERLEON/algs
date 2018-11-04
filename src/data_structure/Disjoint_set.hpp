/* Finds group id to which a vertex belongs
 * Complexity: O(1) - time & space
 */
int find(vector<int>& parent, int vert)
{
    if (parent[vert] == vert) return vert;
    return parent[vert] = find(parent, parent[vert]);
}

/* Unites two groups to which two vertices belongs
 * Complexity: O(1) - time & space
 */
bool unite(vector<int>& parent, int vert_a, int vert_b)
{
    int group_a = find(parent, vert_a), group_b = find(parent, vert_b);
    if (group_a == group_b) return false;

    if (rand() & 1) swap(group_a, group_b);

    parent[group_a] = group_b;

    return true;
}