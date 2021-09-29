#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums)
{
    int i = 0, j = 1, n = nums.size();

    while (i < n && j < n)
    {
        while (i < n and nums[i] % 2 == 0)
        {
            i += 2;
        }
        while (j < n and nums[j] % 2 == 1)
        {
            j += 2;
        }
        if (i < n and j < n)
        {
            swap(nums[i], nums[j]);
        }
    }

    return nums;
}