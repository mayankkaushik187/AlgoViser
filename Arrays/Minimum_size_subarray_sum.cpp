#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int res = INT_MAX;
    int sum = 0;
    int n = nums.size();
    for (int i = 0, j = 0; j < n;)
    {
        while (sum < target && j < n)
        {
            sum += nums[j++];
        }

        while (sum >= target && i < n)
        {
            res = min(res, j - i);
            sum -= nums[i++];
        }
    }
    return res == INT_MAX ? 0 : res;
}