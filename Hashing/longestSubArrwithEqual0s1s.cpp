#include <bits/stdc++.h>
using namespace std;

int arrSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void replaceZeros(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
    }
}

int solve(int arr[], int n)
{
    int subSum = 0;
    int maxLen = 0;
    unordered_map<int, int> um;
    replaceZeros(arr, n);
    for (int i = 0; i < n; i++)
    {
        subSum += arr[i];
        if (subSum == 0)
        {
            maxLen = i + 1;
        }
        if (um.find(subSum) == um.end())
        {
            um[subSum] = i;
        }
        if (um.find(subSum - 0) != um.end())
        {
            maxLen = max(maxLen, i - um[subSum - 0]);
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {1, 1, 0, 0, 1, 1, 0};
    int n = 7;
    cout << solve(arr, n);
    return 0;
}