class Solution {
public:
  //leetcode 5
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string res;
        int mlen = INT_MIN;
        for(int g = 0 ; g < n ;g++){
            for(int i = 0, j = g ; j < n ; j++, i++){
                if(g == 0){
                    dp[i][j] = true;
                }else if(g == 1){
                    if(s[i] == s[j])dp[i][j] = true;
                    else dp[i][j] = false;
                }else{
                    if(s[i] == s[j] and dp[i+1][j-1]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j] and j - i + 1 > mlen){
                    mlen = j - i + 1;
                    res = s.substr(i,mlen);
                }
            }
        }
        return res;
    }
};
