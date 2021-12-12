class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
        }
        vector<vector<int>> dp(n + 1,vector<int>(sum + 1,INT_MAX));
        
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;
        }
        for(int i = 0 ; i <= sum ; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= sum ; j++){
                if(j - arr[i-1] >= 0){
                    dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return sum % 2 == 0 and dp[n][sum/2];
        
    }
};
