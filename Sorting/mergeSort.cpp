#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int n = mid - low + 1;
    int m = high - mid;

    int left[n];
    int right[m];
    for (int idx = 0; idx < n; idx++)
    {
        left[idx] = a[idx + low];
    }
    for (int idx = 0; idx < m; idx++)
    {
        right[idx] = a[idx + (mid + 1)];
    }

    int i = 0, j = 0, k = low;

    while (i < n && j < m)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < m)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (r > l)
    {
        int mid = l + r >> 1;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    int arr[] = {6, 4, 1, 3, 5, 2, 1};
    int l = 0;
    int r = 6;
    mergeSort(arr, l, r);
    for (int e : arr)
    {
        cout << e << " ";
    }
    return 0;
}