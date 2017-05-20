/* Centroid decomposition of a tree
 * Complexity: N*logN
 * Input: g {graph}; Output: dg {decomposition of the graph} */
#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

int n, m;
vector<int> g[MAX], dg[MAX];
int s[MAX], used[MAX], is_centroid[MAX];

//n - number of vertices in current tree
int find_centroid(int v, int n) {
    used[v] = 1;
    s[v] = 1;
    bool centroid = true;

    int ans = -1;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to] || is_centroid[to]) continue;

        int t = find_centroid(to, n);
        if (t != -1) return t;

        s[v] += s[to];
        centroid &= s[to] <= n/2;
    }
    centroid &= n-s[v] <= n/2;
    ans = centroid ? v : ans;

    return ans;
}

int count_vertices(int v) {
    int ans = 1;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to] || is_centroid[to]) continue;
        ans += count_vertices(to);
    }
    return ans;
}

int decompose(int root) {
    memset(used, 0, sizeof used);
    int cnt = count_vertices(root);

    memset(used, 0, sizeof used);
    int v = find_centroid(root, cnt);
    is_centroid[v] = 1;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!is_centroid[to]) {
            int sub_v = decompose(to);

            dg[v].push_back(sub_v);
            dg[sub_v].push_back(v);
        }
    }

    return v;
}

main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    decompose(0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < dg[i].size(); ++j)
            if (i < dg[i][j]) cout << i+1 << " " << dg[i][j]+1 << endl;
}
