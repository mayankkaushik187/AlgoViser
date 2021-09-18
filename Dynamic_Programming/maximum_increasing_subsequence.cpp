#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MSIS(int arr[], int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; i++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{

    int n = 3;

    int arr[] = {5, 10, 20};

    cout << MSIS(arr, n);

    return 0;
}