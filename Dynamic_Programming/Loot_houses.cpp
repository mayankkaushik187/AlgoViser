#include <bits/stdc++.h>
using namespace std;
int mem_ans(int *arr, int n, vector<int> &dp)
{
    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }

    return dp[n - 1];
}

int maxMoneyLooted(int *arr, int n)
{
    //Write your code here
    vector<int> dp(n + 1, INT_MIN);
    return mem_ans(arr, n, dp);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}