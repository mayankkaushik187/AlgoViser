#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kthSmallest(int a[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int p = partition(a, low, high);
        if (p == k - 1)
        {
            return p;
        }
        else if (p > k - 1)
        {
            high = p - 1;
        }
        else
        {
            low = p + 1;
        }
    }
    return -1; // when k is given out of array bounds
}

int main()
{

    int arr[] = {10, 4, 5, 8, 11, 6, 26};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int index = kthSmallest(arr, n, k);

    cout << arr[index];
}