#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    //Write your code here
    if (n == 0 || m == 0)
    {
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    //filling 1st row
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = (arr[0][i] == 1) ? 0 : 1;
    }
    //filling 1st column
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (arr[i][0] == 1) ? 0 : 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            else
                dp[i][j] = 0;
        }
    }

    //check for max;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, dp[i][j]);
        }
    }

    return res;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}