#include <bits/stdc++.h>
using namespace std;

int subset_sum_recur(int arr[], int n, int sum)
{
    if (n == 0)
    {
        return sum == 0 ? 1 : 0;
    }

    return subset_sum_recur(arr, n - 1, sum) + subset_sum_recur(arr, n - 1, sum - arr[n - 1]);
}

int subset_sum_dp(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int n = 4;
    int arr[] = {10, 20, 15, 2};
    cout << "Recursion = " << subset_sum_recur(arr, n, 25) << endl;
    cout << "Dp Solution = " << subset_sum_dp(arr, n, 25) << endl;
}