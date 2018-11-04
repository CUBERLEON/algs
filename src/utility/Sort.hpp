/* Bubble sort
 * Complexity: O(N^2) - time, O(1) - space
 */
void bubble_sort(int* a, int n)
{
    for (int k = 0; ; ++k)
    {
        bool swapped = false;
        for (int i = 0; i < n-1 - k; ++i)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/* Selection sort
 * Complexity: O(N^2) - time, O(1) - space
 */
void selection_sort(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int m = i;
        for (int j = i+1; j < n; ++j)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        swap(a[i], a[m]);
    }
}

/* Insertion sort
 * Complexity: O(N^2) - time, O(1) - space
 */
void insertion_sort(int* a, int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = i-1; j >= 0 && a[j] > a[j+1]; --j)
        {
            swap(a[j], a[j+1]);
        }
    }
}

/* Merge sort
 * Complexity: O(N*Log(N)) - time, O(N) - space
 */
void merge(int* a, int n1, int n2)
{
    int* m = new int[n1+n2];
    int i = 0, j = 0;

    for (int k = 0; k < n1+n2; ++k)
    {
        if (i < n1 && (j >= n2 || a[i] <= a[n1 + j]))
        {
            m[k] = a[i++];
        }
        else
        {
            m[k] = a[n1 + j++];
        }
    }

    memcpy(a, m, (n1+n2) * sizeof(int));
    delete[] m;
}

void merge_sort(int* a, int n)
{
    if (n < 2) return;

    int n1 = n/2, n2 = n-n1;

    merge_sort(a, n1);
    merge_sort(a+n1, n2);

    merge(a, n1, n2);
}

/* Quick sort
 * Complexity: O(N*Log(N)) - time, O(1) - space
 */
int partition(int* a, int n)
{
    int rand_index = rand() % n;
    swap(a[rand_index], a[n-1]);

    int x = a[n-1];
    int pivot = -1;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= x)
        {
            swap(a[i], a[++pivot]);
        }
    }

    return pivot; // pivot cannot be negative (at least one swap is performed when i=n-1)
}

void quick_sort(int* a, int n)
{
    if (n <= 0) return;

    int pivot = partition(a, n);

    quick_sort(a, pivot);
    quick_sort(a + pivot+1, n - (pivot+1));
}

/* Radix sort
 * Complexity: O(N*R) - time, O(N+R) - space, where R - size of the radix
 * R=10
 */
void radix_sort(int* a, int n)
{
    queue<int> m[10];

    int c = 1;
    for (int pos = 0; pos <= 9; ++pos)
    {
        c *= 10;

        int proceed = 0;
        for (int i = 0; i < n; ++i)
        {
            int cur = (a[i] / c) % 10;
            proceed |= cur > 0;
            m[cur].push(a[i]);
        }

        if (!proceed) break;

        int p = 0;
        for (int digit = 0; digit <= 9; ++digit)
        {
            while (!m[digit].empty())
            {
                a[p++] = m[digit].front();
                m[digit].pop();
            }
        }
    }
}

/* Heap sort
 * Complexity: O(N*Log(N)) - time, O(N) - space
 */
void heapify(int* a, int pos, int n)
{
    int l = 2*pos+1, r = l+1;

    while (l < n)
    {
        int next = pos;
        if (a[l] > a[pos]) next = l;
        if (r < n && a[r] > a[next]) next = r;
        if (next == pos) break;

        swap(a[next], a[pos]);
        pos = next;

        l = 2*pos+1, r = l+1;
    }
}

void heap_sort(int* a, int n)
{
    // building a heap
    for (int i = n/2; i >= 0; --i)
    {
        heapify(a, i, n);
    }

    // extracting largest elements and shrinking the heap
    for (int i = n-1; i >= 1; --i)
    {
        swap(a[i], a[0]);
        heapify(a, 0, i);
    }
}
