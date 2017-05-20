/* Sorts 1-dimensional array
 * Complexity: N*logN
 */
#include <bits/stdc++.h>
using namespace std;

void merge(int* a, int n1, int n2) {
    int* m = new int[n1+n2];

    int i = 0, j = 0;
    for (int k = 0; k < n1+n2; ++k) {
        if (i < n1 && (j >= n2 || a[i] <= a[n1 + j]))
            m[k] = a[i++];
        else
            m[k] = a[n1 + j++];
    }
    memcpy(a, m, (n1+n2) * sizeof(int));
    delete[] m;
}

void mergeSort(int* a, int n) {
    if (n > 1) {
        int n1 = n/2, n2 = n-n1;
        mergeSort(a, n1);
        mergeSort(a+n1, n2);
        merge(a, n1, n2);
    }
}

main() {
    int n = 10;
    int a[] = {9, 1, 8, 5, 2, 7, 4, 3, 10, 6};
    mergeSort(a, n);
    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i<n-1 ? ' ' : '\n');
}
