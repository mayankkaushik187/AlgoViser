//leetcode 494
//Backtracking
class Solution {
    public:
        int dfs(vector < int > & nums, int target, int index, int sum) {
            if (index == nums.size()) {
                return sum == target;
            }
            return dfs(nums, target, index + 1, sum + nums[index]) + dfs(nums, target, index + 1, sum - nums[index]);
        }
    int findTargetSumWays(vector < int > & nums, int target) {
        return dfs(nums, target, 0, 0);
    }
};

