#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    //code here
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
int main()
{
    string x = "abcd";
    string y = "xycd";

    cout << shortestCommonSupersequence(x, y, 4, 4);
    return 0;
}