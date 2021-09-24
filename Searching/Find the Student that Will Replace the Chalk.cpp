#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<long long> &arr, long long target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}
int chalkReplacer(vector<int> &chalk, int k)
{
    int n = chalk.size();
    vector<long long> prefix(n);
    prefix[0] = chalk[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + chalk[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += chalk[i];
    }

    long long target = k % sum;

    int res = binarySearch(prefix, target);
    return res;
}