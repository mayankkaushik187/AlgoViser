class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int ans = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),greater());
        int sum = 0;
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            res.push_back(nums[i]);
            if(2*sum > ans){
                break;
            }
        }
        return res;
    }
};
