/*leetcode 213
the idea is to make two seperate vectors and pass them to find the normal maximum money he can make tonight
in the vectors make sure to be certain with the fact that we can choose [0,n-2] or [1,n-1];
and finally return whichever gives us the maximum value
*/
#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }

    return dp[nums.size() - 1];
}
int rob(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> v1(nums.begin() + 1, nums.end());
    vector<int> v2(nums.begin(), nums.end() - 1);
    return max(helper(v1), helper(v2));
}
