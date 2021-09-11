#include <bits/stdc++.h>
using namespace std;
int maxSum_With_No_Consec_Ele_recursion(int arr[], int n) //Fibonacci Recurrence
{
    if (n == 0)
    {
        return INT_MIN;
    }
    if (n == 1)
    {
        return arr[n - 1];
    }
    if (n == 2)
    {
        return max(arr[n - 1], arr[n - 2]);
    }

    return max(maxSum_With_No_Consec_Ele_recursion(arr, n - 1), maxSum_With_No_Consec_Ele_recursion(arr, n - 2) + arr[n - 1]);
}

int maxSum_dp(int arr[], int n) // Linear Complexity both for time and space
{
    vector<int> dp(n + 1, 0);

    dp[1] = arr[0];
    dp[2] = max(arr[1], arr[2]);

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main()
{
    int n = 5;
    int arr[] = {10, 20, 3, 4, 60};
    cout << "Recursive ans = " << maxSum_With_No_Consec_Ele_recursion(arr, n);
    cout << endl;
    cout << "Dp ans = " << maxSum_dp(arr, n);
    return 0;
}