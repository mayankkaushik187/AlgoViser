#include <bits/stdc++.h>
using namespace std;
long long int maxSumWithK(long long int arr[], long long int n, long long int k)
{
    long long int maxSum = arr[0];
    vector<long long int> maxArr(n);
    maxArr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxSum = max<long long int>(arr[i], maxSum + arr[i]);
        maxArr[i] = maxSum;
    }
    long long int maxWindowSum = 0;
    for (int i = 0; i < k; i++)
    {
        maxWindowSum += arr[i];
    }
    long long int currMax = maxWindowSum;
    for (int i = k; i < n; i++)
    {
        maxWindowSum += arr[i];
        maxWindowSum -= arr[i - k];
        currMax = max<long long int>(currMax, maxWindowSum);

        currMax = max<long long int>(currMax, maxWindowSum + maxArr[i - k]);
    }
    return currMax;
}