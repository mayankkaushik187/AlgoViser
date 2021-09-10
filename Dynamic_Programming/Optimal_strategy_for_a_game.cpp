#include <bits/stdc++.h>
using namespace std;

int optimal_strategy(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < dp.size(); g++)
    {

        for (int i = 0, j = g; j < dp.size(); i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = arr[i];
            }
            else if (g == 1)
            {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else
            {
                int val1 = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                int val2 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);

                int res = max(val1, val2);
                dp[i][j] = res;
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{

    int n = 4;

    int arr[] = {20, 5, 4, 6};

    cout << optimal_strategy(arr, n);

    return 0;
}