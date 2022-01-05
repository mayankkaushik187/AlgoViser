class Solution {
public:
    const int N = 2005;
    bool checkPartitioning(string s) {        
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
            
        for(int i = n - 1;  i >= 0 ; i--){
            for(int j = i ; j < n ; j++){
                int len = j - i + 1;
                if(len == 1){
                    dp[i][j] = 1;
                }else if(len == 2){
                    dp[i][j] = s[i] == s[j];
                }else{
                    dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1];
                }
            }
        }
        for(int f = 0 ; f < n ; f++){
            for(int s = f + 2 ; s < n ; s++){
                int first = dp[0][f];
                int sec = dp[f + 1][s - 1];
                int third = dp[s][n - 1];
                if(first and sec and third)return true;
            }
        }
        return false;
    }
    /*
    
    
    */
};
