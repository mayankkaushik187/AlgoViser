
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxm = 0;
        int res = 0;
        vector<pair<int,int>> dp(n,{1,1});
        for(int i = 0 ; i < nums.size() ; i++){
        	for(int j = i - 1; j >= 0 ; j--){
        		if(nums[j] < nums[i]){
        			if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1,dp[j].second};
        		}
        	}
            if(maxm == dp[i].first)res += dp[i].second;
            if(maxm < dp[i].first){
                maxm = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
};
