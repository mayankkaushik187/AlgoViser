#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int *input, int n)
{
    // Write your code here
    vector<int> dp(n, 1);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] >= input[i])
            {
                continue;
            }

            int possibleAns = dp[j] + 1;
            dp[i] = max(dp[i], possibleAns);
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}