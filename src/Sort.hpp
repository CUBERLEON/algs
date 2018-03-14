/* Sorting of an 1-dimensional array */
#include <bits/stdc++.h>

namespace Sort
{
    void Print(int* a, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::printf("%d%c", a[i], i<n-1 ? ' ' : '\n');
        }
    }

    /* Bubble sort
     * Complexity: N^2 */
    void BubbleSort(int* a, int n)
    {
        for (int k = 0; ; ++k)
        {
            bool swapped = false;
            for (int i = 0; i < n-1 - k; ++i)
            {
                if (a[i] > a[i+1])
                {
                    std::swap(a[i], a[i+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    /* Selection sort
     * Complexity: N^2 */
    void SelectionSort(int* a, int n)
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
            std::swap(a[i], a[m]);
        }
    }

    /* Insertion sort
     * Complexity: N^2 */
    void InsertionSort(int* a, int n)
    {
        for (int i = 1; i < n; ++i)
        {
            for (int j = i-1; j >= 0 && a[j] > a[j+1]; --j)
            {
                std::swap(a[j], a[j+1]);
            }
        }
    }

    /* Merge sort
     * Complexity: N*logN */
    void Merge(int* a, int n1, int n2)
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

        std::memcpy(a, m, (n1+n2) * sizeof(int));
        delete[] m;
    }

    void MergeSort(int* a, int n)
    {
        if (n < 2) return;

        int n1 = n/2, n2 = n-n1;

        MergeSort(a, n1);
        MergeSort(a+n1, n2);

        Merge(a, n1, n2);
    }

    /* Quick sort
     * Complexity: N*logN */
    int Partition(int* a, int n)
    {
        std::swap(a[std::rand() % n], a[n-1]);
        int x = a[n-1];
        int pivot = -1;

        for (int i = 0; i < n; ++i)
        {
            if (a[i] <= x)
            {
                std::swap(a[i], a[++pivot]);
            }
        }

        return pivot; //pivot cannot be negative (at least one swap is performed when i=n-1)
    }

    void QuickSort(int* a, int n)
    {
        if (n <= 0) return;

        int pivot = Partition(a, n);

        QuickSort(a, pivot);
        QuickSort(a + pivot+1, n - (pivot+1));
    }

    /* Radix sort
     * Complexity: N*R, R - size of the radix, R=10 */
    void RadixSort(int* a, int n)
    {
        std::queue<int> m[10];

        for (int c = 1; ; c *= 10)
        {
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
     * Complexity: N*logN */
    void Heapify(int* a, int pos, int n)
    {
        int l = 2*pos+1, r = l+1, p = (pos-1)/2; //left, right children and parent indices

        //going up
        while (pos > 0 && a[p] < a[pos])
        {
            std::swap(a[p], a[pos]);
            pos = p;

            p = (pos-1)/2;
        }

        //going down
        while (l < n)
        {
            int next = pos;
            if (a[l] > a[pos]) next = l;
            if (r < n && a[r] > a[next]) next = r;
            if (next == pos) break;

            std::swap(a[next], a[pos]);
            pos = next;

            l = 2*pos+1, r = l+1;
        }
    }

    void HeapSort(int* a, int n)
    {
        //building a heap
        for (int i = 1; i < n; ++i)
        {
            Heapify(a, i, i+1);
        }

        //extracting largest elements and shrinking the heap
        for (int i = n-1; i >= 1; --i)
        {
            std::swap(a[i], a[0]);
            Heapify(a, 0, i);
        }
    }
}