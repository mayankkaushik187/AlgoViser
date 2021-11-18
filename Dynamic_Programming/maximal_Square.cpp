class Solution {
public:
//leetcode 221
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int size = 0;
        for(int i = 0 ; i < m ; i++){
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            size = max(size,dp[0][i]);
        }
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            size = max(size,dp[i][0]);
        }
        for(int i = 1; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                    size = max(size,dp[i][j]);
                }

            }
        }
        return size * size;
    }
};
