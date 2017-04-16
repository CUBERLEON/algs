/* Centroid of a tree
 * Complexity: N
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

int n, m;
vector<int> g[MAX];
int s[MAX], used[MAX];

int find_centroid(int v) {
    used[v] = 1;
    s[v] = 1;
    bool centroid = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to]) continue;

        int t = find_centroid(to);
        if (t != -1)
            return t;

        s[v] += s[to];
        centroid &= s[to] <= n/2;
    }
    centroid &= n-s[v] <= n/2;

    return (centroid ? v : -1);
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << find_centroid(0)+1 << endl;

    return 0;
}
