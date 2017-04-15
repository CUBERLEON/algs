/*
Title: Merge sort
Description: sorts 1-dimensional array of integers
Technique: Divide & conquer
Time complexity: NlogN
Memory usage: N
*/

#include <bits/stdc++.h>

using namespace std;

void mergeSort(int* arr, int n) {
    if (n <= 1)
        return;
    else {
        int n1 = n/2, n2 = n - n/2;

        mergeSort(arr, n1);
        mergeSort(arr + n1, n2);
        
        int i, j;
        int* m = new int[n];
        i = j = 0;
        for (int k = 0; k < n; ++k) {
            if (i < n1 && (j >= n2 || arr[i] < arr[n1 + j])) {
                m[k] = arr[i];
                ++i;
            }
            else {
                m[k] = arr[n1 + j];
                ++j;
            }
        }

        for (int k = 0; k < n; ++k)
            arr[k] = m[k];
        delete[] m;
    }
}

int main() {
    int n = 10;
    int a[] = { 9, 1, 8, 5, 2, 7, 4, 3, 10, 6 };
    mergeSort(a, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    
    return 0;
}
