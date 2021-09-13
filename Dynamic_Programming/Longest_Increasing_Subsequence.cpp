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

int ceilArr(int tail[], int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (tail[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return r;
}

int longestSubsequence_binarySearch(int n, int arr[])
{
    int len = 1;

    int tail[n];
    tail[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilArr(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
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