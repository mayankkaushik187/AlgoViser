#include <bits/stdc++.h>
using namespace std;

int count_n_bsts(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int lans = count_n_bsts(i - 1);
        int rans = count_n_bsts(n - i);

        res += lans * rans;
    }
    
    return res;
}

int count_n_bsts_dp(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1]; // this is basically saying that dp[n] += dp[i-1]*dp[n-i] this recurrence can be related to our naive recursive approach
        }
    }

    return dp[n];
}

int main()
{
    int n = 6;
    cout << count_n_bsts(n);
    return 0;
}