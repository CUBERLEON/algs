/*
Title: Count invertions
Description: counts invertions in 1-dimensional array of integers
Technique: Divide & conquer
Time complexity: NlogN
Memory usage: N
*/

#include <bits/stdc++.h>
using namespace std;

int countInvertionsAux(int* arr, int n) {
    if (n <= 1)
        return 0;
    else {
        int n1 = n/2, n2 = n - n/2;

        int ans = 0;
        ans += countInvertionsAux(arr, n1);
        ans += countInvertionsAux(arr + n1, n2);
        
        int* m = new int[n];
        int i, j;
        i = j = 0;
        for (int k = 0; k < n; ++k) {
            if (i < n1 && (j >= n2 || arr[i] <= arr[n1 + j])) {
                m[k] = arr[i];
                ++i;

                ans += j;
            }
            else {
                m[k] = arr[n1 + j];
                ++j;
            }
        }

        for (int k = 0; k < n; ++k)
            arr[k] = m[k];
        delete[] m;

        return ans;
    }
}

int countInvertions(int* arr, int n) {
    int* b = new int[n];
    for (int i = 0; i < n; ++i)
        b[i] = arr[i];
    int ans = countInvertionsAux(b, n);
    delete[] b;
    return ans;
}

int main() {
    int n = 10;
    int a[] = { 9, 1, 8, 5, 2, 7, 4, 3, 10, 6 };

    printf("Invertions: %d\n", countInvertions(a, n));

    return 0;
}
