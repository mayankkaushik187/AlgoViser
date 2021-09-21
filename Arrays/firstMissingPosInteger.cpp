#include <bits/stdc++.h>
using namespace std;
//leetcode 41
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] <= n && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]) //check if it lies in range and its is not at its correct position then do the swapping
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
        {
            return i + 1;
        }
    }

    return n + 1;
}