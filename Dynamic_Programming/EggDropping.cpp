#include <bits/stdc++.h>
using namespace std;

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop_recursion(int n, int k) // TC - 2 raised to n
{
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;

    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;

    int minm = INT_MAX, x, res;

    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (int x = 1; x <= k; x++)
    {
        res = max(eggDrop_recursion(n - 1, x - 1), eggDrop_recursion(n, k - x));

        minm = min(minm, res);
    }

    return minm + 1;
}

int eggDropDP(int n, int k)
{ //TC - ((k^2)*n)
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

    //if the eggs are 0
    //if the floors are 0 --> ans = 0
    //if the floors are 1 --> ans = 1
    //if the eggs are 1 --> ans = floors;

    for (int e = 1; e <= n; e++)
    {
        dp[0][e] = 0;
        dp[1][e] = 1;
    }
    for (int f = 2; f <= k; f++)
    {
        dp[f][1] = f;
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            for (int x = 1; x <= i; x++)
            {
                dp[i][j] = min(dp[i][j], 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
            }
        }
    }

    return dp[k][n];
}

// Driver program to test
// to pront printDups
int main()
{
    int n = 2, k = 10;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k
         << " floors is "
         << eggDrop_recursion(n, k) << "and" << eggDropDP(n, k) << endl;
    return 0;
}