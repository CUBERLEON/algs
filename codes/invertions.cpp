/* Counts invertions in 1-dimensional array
 * Invertion: a[i] > a[j], where i < j
 * Complexity: N*logN */
#include <bits/stdc++.h>
using namespace std;

int merge(int* a, int n1, int n2) {
    int* m = new int[n1+n2];

    int i = 0, j = 0, ans = 0;
    for (int k = 0; k < n1+n2; ++k) {
        if (i < n1 && (j >= n2 || a[i] <= a[n1 + j])) {
            m[k] = a[i++];
            ans += j;
        }
        else {
            m[k] = a[n1 + j++];
        }
    }
    memcpy(a, m, (n1+n2) * sizeof(int));
    delete[] m;

    return ans;
}

int countInvertions(int* a, int n) {
    int ans = 0;
    if (n > 1) {
        int n1 = n/2, n2 = n-n1;
        ans += countInvertions(a, n1);
        ans += countInvertions(a+n1, n2);
        ans += merge(a, n1, n2);
    }
    return ans;
}

main() {
    int a[] = {9, 1, 8, 5, 2, 7, 4, 3, 10, 6};
    cout << countInvertions(a, 10) << endl; //22
    int b[] = {9, 1, 8};
    cout << countInvertions(b, 3) << endl; //2
}
