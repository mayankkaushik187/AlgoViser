#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int palindromePartitioning_Recur(string s, int i, int j)
{
    if (isPalindrome(s, i, j))
    {
        return 0;
    }
    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        res = min(res, palindromePartitioning_Recur(s, i, k) + palindromePartitioning_Recur(s, k + 1, j) + 1);
    }

    return res;
}

int palPartitioning_DP(string s)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, INT_MAX));

    for (int g = 0; g < dp.size(); g++)
    {
        for (int i = 0, j = g; j < dp.size(); j++, i++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (isPalindrome(s, i, j))
                {
                    dp[i][j] = 0;
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                    }
                }
            }
        }
    }

    return dp[0][dp.size() - 1];
}