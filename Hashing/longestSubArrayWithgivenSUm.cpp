#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int preSum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == sum)
        {
            return i + 1;
        }
        if (m.find(preSum) == m.end())
        {
            m.insert({preSum, i});
        }
        if (m.find(preSum - sum) != m.end())
        {
            maxLen = max(maxLen, i - m[preSum - sum]);
        }
    }
    return maxLen;
}

int main()
{
    int arr[] = {5, 8, -4, -4, 9, -2, 2};
    int n = 7;
    int sum = 0;
    cout << solve(arr, n, sum);
    return 0;
}