class Solution {
public:
    int p;
    double helper(int r,int c,vector<vector<double>>&dp){
        if(r < 0 or c < 0)return 0;
        if(r == 0 and c == 0)return p;
        double &ans = dp[r][c];
        if(ans != -1.0)return ans;
        ans = max(helper(r - 1,c - 1,dp) - 1, 0.0) / 2 + max(helper(r - 1,c,dp) - 1, 0.0) / 2;
        return ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        p = poured;
        vector<vector<double>> dp(query_row + 2,vector<double>(query_glass + 2,-1.0));
        return min(1.0,helper(query_row,query_glass,dp));
    }
};
