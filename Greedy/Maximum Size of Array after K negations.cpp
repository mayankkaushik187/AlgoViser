class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() and nums[i] < 0 and k > 0 ; i++,k--){
            nums[i] = -nums[i];
        }
        int ans = accumulate(nums.begin(),nums.end(),0) - (k % 2) * 2 * *min_element(nums.begin(),nums.end());
        return ans;
    }
};
