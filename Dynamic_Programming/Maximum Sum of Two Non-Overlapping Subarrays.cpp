//Leetcode 1031
class Solution {
    public:
        int helper(vector < int > & nums, int x, int y) {
            int n = nums.size();
            vector < int > dp1(n), dp2(n);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (i < x) {
                    sum += nums[i];
                    dp1[i] = sum;
                } else {
                    sum += nums[i] - nums[i - x];
                    dp1[i] = max(sum, dp1[i - 1]);
                }
            }
            sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (i + y >= n) {
                    sum += nums[i];
                    dp2[i] = sum;
                } else {
                    sum += nums[i] - nums[i + y];
                    dp2[i] = max(dp2[i + 1], sum);
                }
            }
            int res = INT_MIN;
            for (int i = x - 1; i < n - y; i++) {
                res = max(res, dp1[i] + dp2[i + 1]);
            }
            return res;
        }
    int maxSumTwoNoOverlap(vector < int > & nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
};
