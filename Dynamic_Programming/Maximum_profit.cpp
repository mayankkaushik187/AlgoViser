#include <bits/stdc++.h>
using namespace std;

//Problem Link--https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
int maxProfit(int k, int n, int price[])
{
    // code here
    vector<vector<int>> dp(k + 1, vector<int>(n, INT_MIN)); //dp[i][j] means the profit with i transactions in j days

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int maxSoFar = INT_MIN;
            for (int m = 0; m < j; m++)
            {
                maxSoFar = max(maxSoFar, price[j] - price[m] + dp[i - 1][m]);
            }
            dp[i][j] = max(dp[i][j - 1], maxSoFar);
        }
    }

    return dp[k][n - 1];
}