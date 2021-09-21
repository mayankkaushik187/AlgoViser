#include <bits/stdc++.h>
using namespace std;

int bitonic(vector<int> arr, int n)
{
    // code here
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
            left[i] = left[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
            right[i] = right[i + 1] + 1;
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, left[i] + right[i] + 1);
    }

    return res;
}