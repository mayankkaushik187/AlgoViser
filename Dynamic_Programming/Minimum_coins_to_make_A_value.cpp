#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int val)
{
    vector<int> dp(val + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[val];
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, val = 149, n = 11;

    cout << minCoins(arr, n, val);
}