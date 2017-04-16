/*
 * Finds a peak in a 1-dimensional array of distinct integers which at first constantly increses and then decreases
 * Complexity: logN
 */

/*
INPUT:
23
1 2 3 4 5 6 7 8 9 10 11 12 13 16 20 21 25 17 15 13 5 4 2
OUTPUT:
25
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int left = 0, right = n-1, mid;
    while (true) {
        mid = (left + right) >> 1;
        if (mid+1 < n && a[mid] < a[mid+1])
            left = mid+1;
        else if (mid-1 > 0 && a[mid] < a[mid-1])
            right = mid-1;
        else
            break;
    }

    cout << a[left];

    delete[] a;

    return 0;
}
