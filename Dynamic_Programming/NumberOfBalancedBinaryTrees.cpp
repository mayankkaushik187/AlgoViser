#include<bits/stdc++.h>
int balancedBTs(int n) {
    // Write your code here
    if(n <= 1){
        return 1;
    }
    vector<long> dp(n+1,0);
    int mod = 1e9 + 7;
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= n ;i++){
        dp[i] = ((dp[i-1]*dp[i-1])%mod + (2*(dp[i-1]* dp[i-2])%mod)%mod)%mod;
    }
    
    return (int)(dp[n]);
    
}
