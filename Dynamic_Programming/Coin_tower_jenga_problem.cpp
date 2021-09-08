#include <bits/stdc++.h>
using namespace std;
string findWinner(int n, int x, int y)
{
    // Write your code here .
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[x] = 1;
    dp[y] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (!dp[i])
        {
            dp[i] = dp[i - 1] ^ 1;

            if (i - x >= 1)
            {
                dp[i] = max(dp[i], dp[i - x] ^ 1);
            }

            if (i - y >= 1)
            {
                dp[i] = max(dp[i], dp[i - y] ^ 1);
            }
        }
    }
    string sol;
    if (dp[n])
    {
        sol = "Beerus";
    }
    else
    {
        sol = "Whis";
    }

    return sol;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}