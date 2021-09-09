#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MIN;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }
        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != INT_MIN)
        {
            dp[i]++;
        }
    }

    return dp[n];
}

int main()
{

    int n = 5, a = 1, b = 2, c = 3;

    cout << maxCuts(n, a, b, c);
}