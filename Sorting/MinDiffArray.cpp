#include <bits/stdc++.h>
using namespace std;

int minDiff(int arr[], int n)
{
    if (n == 1)
    {
        return INT_MAX;
    }

    int res = 0;
    sort(arr, arr + n);
    res = abs(arr[1] - arr[0]);

    for (int i = 2; i < n; i++)
    {
        int curDiff = abs(arr[i] - arr[i - 1]);
        res = min(res, curDiff);
    }

    return res;
}

int main()
{
    int arr[] = {1, 8, 12, 5, 18};
    int n = 5;
    cout << minDiff(arr, n);
    return 0;
}