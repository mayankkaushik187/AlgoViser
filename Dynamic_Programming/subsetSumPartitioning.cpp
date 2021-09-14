#include <bits/stdc++.h>
using namespace std;

bool findPartition(int arr[], int n)
{
    // code here
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }

    sum = sum / 2;
    vector<vector<bool>> dp(2, vector<bool>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i % 2][j] = 1;
            }
            else if (i == 0)
            {
                dp[i % 2][j] = 0;
            }

            else if (j >= arr[i - 1])
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j - arr[i - 1]] || dp[(i + 1) % 2][j];
            }
            else
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
            }
        }
    }
    return dp[n % 2][sum];
}

int main()
{
    int arr[] = {1, 3, 5};
    int n = 3;
    findPartition(arr, n) ? cout << "YES" : cout << "NO";
}