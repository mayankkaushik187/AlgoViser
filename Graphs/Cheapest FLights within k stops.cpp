class Solution {
public:
    //leetcode 787
    //dp with graphs bellman ford algo
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k + 2, vector<int>(n,INT_MAX));//dp[i][j] = min dist to reach j with i stops at max
        for(int i = 0 ; i <= k + 1 ; i++){
            dp[i][src] = 0;
        }
        for(int i = 1; i <= k + 1 ; i++){
            for(auto f : flights){
                int u = f[0],v = f[1], w = f[2];
                if(dp[i-1][u] != INT_MAX){//ki edge ke pehle node tak pohachne ka min dist INF to nahi hai
                    dp[i][v] = min(dp[i][v],dp[i-1][u] + w);
                }
            }
        }
        return dp[k+1][dst] == INT_MAX ? -1 : dp[k+1][dst];
     }
};
