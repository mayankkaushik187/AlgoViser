int countMin(string str){
    //complete the function here
        int n = str.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int g = 0 ; g < n ; g++){
            for(int i = 0 , j = g ; j < dp.size() ; j++,i++){
                if(g == 0){
                    dp[i][j] = 1;
                }else{
                    if(str[i] == str[j]){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }else{
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return n - dp[0][n-1];
    }
