class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0 or nums.size() == 1)return nums;
        
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> prev_index(n,-1);
        sort(nums.begin(),nums.end());
        int maxEle = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0; j < i ; j++){
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev_index[i] = j;
                }
            }
            if(dp[maxEle] < dp[i]){
                maxEle = i;
            }
        }
        vector<int> temp;
        int t = maxEle;
        while(t >= 0){
            temp.push_back(nums[t]);
            t = prev_index[t];
        }
        return temp;
    }
};
