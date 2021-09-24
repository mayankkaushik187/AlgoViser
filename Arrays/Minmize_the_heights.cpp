#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    // code here
    int minm = 0, maxm = 0, res = 0;
    sort(arr, arr + n);
    res = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k >= 0)
        {
            maxm = max(arr[i - 1] + k, arr[n - 1] - k);
            minm = min(arr[i] - k, arr[0] + k);
            res = min(res, maxm - minm);
        }
    }
    return res;
}