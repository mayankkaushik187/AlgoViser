#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

int minJumps(int arr[], int n)
{

    int dp[n];
    int i, j;

    dp[0] = 0;

    for (i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    return dp[n - 1];
}

int main()
{

    int arr[] = {3, 4, 2, 1, 2, 1}, n = 6;

    cout << minJumps(arr, n);
}