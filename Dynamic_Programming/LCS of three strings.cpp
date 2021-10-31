int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
    for(int i = 0 ; i <= n1 ; i++){
        for(int j = 0 ; j <= n2 ; j++){
            for(int k = 0 ; k <= n3 ; k++){
                if(i == 0 or j == 0 or k == 0){
                    dp[i][j][k] = 0;
                }
                else if(A[i-1] == B[j-1] and A[i-1] == C[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[n1][n2][n3];
    
    
}
