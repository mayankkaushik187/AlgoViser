#include <bits/stdc++.h>
using namespace std;
//watch sumeet sirs explanation to get better understanding

int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here
    int **dp = new int *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
    }
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; j++, i++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];
            }
            else
            {
                int minm = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int left_side_cost = dp[i][k];
                    int right_side_cost = dp[k + 1][j];
                    int total_cost = left_side_cost + right_side_cost + arr[i] * arr[k + 1] * arr[j + 1];

                    minm = min(minm, total_cost);
                }
                dp[i][j] = minm;
            }
        }
    }

    return dp[0][n - 1];
}

int matrixChainRecur(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int res = 1e9;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, matrixChainRecur(arr, i, k) + matrixChainRecur(arr, k, j) + arr[i] * arr[k] * arr[j]);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);
    cout << matrixChainRecur(arr, 0, n - 1);

    delete[] arr;
}