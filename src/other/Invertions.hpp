/* Counts invertions in an 1-dimensional array
 * Invertion: a[i] > a[j], where i < j
 * Complexity: N*logN */
int merge(int* a, int n1, int n2)
{
    int* m = new int[n1+n2];

    int i = 0, j = 0, ans = 0;
    for (int k = 0; k < n1+n2; ++k) {
        if (i < n1 && (j >= n2 || a[i] <= a[n1 + j]))
        {
            m[k] = a[i++];
            ans += j;
        }
        else
        {
            m[k] = a[n1 + j++];
        }
    }
    memcpy(a, m, (n1+n2) * sizeof(int));
    delete[] m;

    return ans;
}

int count_invertions(int* a, int n)
{
    int ans = 0;
    if (n > 1)
    {
        int n1 = n/2, n2 = n-n1;
        ans += count_invertions(a, n1);
        ans += count_invertions(a+n1, n2);
        ans += merge(a, n1, n2);
    }
    return ans;
}
