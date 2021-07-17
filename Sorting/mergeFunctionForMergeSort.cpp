#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int n = mid - low + 1;
    int m = high - (mid + 1) + 1;

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