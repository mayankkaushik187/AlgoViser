#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    //Write your code here
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = input[m - 1][n - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        dp[m - 1][i] = dp[m - 1][i + 1] + input[m - 1][i];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + input[i][j];
        }
    }

    return dp[0][0];
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}