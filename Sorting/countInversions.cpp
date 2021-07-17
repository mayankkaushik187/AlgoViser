#include <bits/stdc++.h>
using namespace std;

int countAndMerge(int arr[], int low, int mid, int high)
{
    int n = mid - low + 1;
    int m = high - mid;
    int left[n], right[m];
    for (int idx = 0; idx < n; idx++)
    {
        left[idx] = arr[idx + low];
    }
    for (int idx = 0; idx < m; idx++)
    {
        right[idx] = arr[idx + mid + 1];
    }

    int i = 0, j = 0, res = 0, k = low;

    while (i < n && j < m)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i];
            i++;
        }
        else
        {
            arr[k++] = right[j];
            j++;
            res = res + (n - i);
        }
    }
    while (i < n)
    {
        arr[k++] = left[i++];
    }
    while (j < m)
    {
        arr[k++] = right[j++];
    }
    return res;
}

int countInv(int arr[], int low, int high)
{
    int res = 0;
    if (low < high)
    {
        int mid = low + high >> 1;
        res += countInv(arr, low, mid);
        res += countInv(arr, mid + 1, high);
        res += countAndMerge(arr, low, mid, high);
    }
    return res;
}

int main()
{

    int arr[] = {4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countInv(arr, 0, n - 1);
}
