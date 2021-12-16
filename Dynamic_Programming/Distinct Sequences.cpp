class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<vector<unsigned int>> dp(n + 1,vector<unsigned int>(m + 1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= m ; i++){
            dp[0][i] = 1;
        }
        
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n ; j++){
                if(s[i-1] == t[j-1]){
                    dp[j][i] = dp[j][i-1] + dp[j-1][i-1];
                }else{
                    dp[j][i] = dp[j][i-1];
                }
            }
        }
        return dp[n][m];
        
    }
};
