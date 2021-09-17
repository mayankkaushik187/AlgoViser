#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int target, int index)
{
    if (target < 0)
    {
        return;
    }
    else if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    else
    {
        for (int i = index; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            helper(res, temp, nums, target - nums[i], i);
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, candidates, target, 0);

    return res;
}