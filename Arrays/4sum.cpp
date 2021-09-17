#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums.size() < 4)
    {
        return {};
    }
    if (nums[0] == 1e9)
    {
        return {};
    }
    if ((int)(nums[0] * 4) > target)
    {
        return {};
    }
    if ((int)(nums[nums.size() - 1] * 4) < target)
    {
        return {};
    }
    for (int l = 0; l <= nums.size() - 4; l++)
    {
        int index = l + 1;
        while (l + 1 < nums.size() - 3 && nums[l + 1] == nums[l])
            l++;
        for (int i = index; i <= nums.size() - 3; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (i + 1 < nums.size() - 2 && nums[i + 1] == nums[i])
                i++;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (j + 1 < k && nums[j + 1] == nums[j])
                        j++;
                    while (j < k - 1 && nums[k - 1] == nums[k])
                        k--;

                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] + nums[l] > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(arr, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
    }
    return 0;
}