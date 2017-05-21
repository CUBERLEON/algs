/* Centroid of a tree
 * Complexity: N
 * Input: g {tree} */
#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

vector<int> g[MAX];
int n, s[MAX], used[MAX];

int find_centroid(int v) {
    used[v] = 1;
    s[v] = 1;
    bool centroid = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (used[to]) continue;

        int t = find_centroid(to);
        if (t != -1) return t;

        s[v] += s[to];
        centroid &= s[to] <= n/2;
    }
    centroid &= n-s[v] <= n/2;

    return (centroid ? v : -1);
}

main() {
    n = 8;
    g[4] = { 3, 5 };
    g[3] = { 4, 0, 1, 2 };
    g[5] = { 4, 6, 7 };
    g[0] = { 3 };
    g[1] = { 3 };
    g[2] = { 3 };
    g[6] = { 5 };
    g[7] = { 5 };

    cout << find_centroid(0) << endl; //4
}
