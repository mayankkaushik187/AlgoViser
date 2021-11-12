class Solution {
public:
  //leetcode 209
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, l = 0, h = 0, n = nums.size();
        int sum = 0;
        while(h < n){
            sum += nums[h++];
            while(sum >= target){
                ans = min(ans,h - l);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
