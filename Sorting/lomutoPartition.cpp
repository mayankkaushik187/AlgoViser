#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int low, int high)
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

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int l = 0;
    int h = sizeof(arr) / sizeof(arr[0]) - 1;
    lomutoPartition(arr, l, h);
    return 0;
}