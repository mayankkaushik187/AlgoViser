#include <bits/stdc++.h>
using namespace std;
//leetcode 40
void helper(vector<vector<int>> &res, vector<int> &temp, vector<int> nums, int target, int index)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    else
    {
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i - 1] == nums[i])
            {
                continue;
            }
            temp.push_back(nums[i]);
            helper(res, temp, nums, target - nums[i], i + 1);
            temp.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    helper(res, temp, candidates, target, 0);

    return res;
}