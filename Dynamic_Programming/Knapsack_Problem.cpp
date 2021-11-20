#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[], int val[], int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
        }
    }

    return dp[n][W];
}

//memo
int memo(int wt[],int val[],int n,int w,int i,int **dp){
	if(i < 0)return 0;
	//memoize
	if(dp[i][w] != -1)return dp[i][w];

	if(wt[i] > w){
		dp[i][w] = memo(wt,val,n,w,i - 1);
	}else{
		dp[i][w] = max(val[i] + memo(wt,val,n,w - wt[i],i-1) , memo(wt,val,n,w,i - 1));
	}
	return dp[i][w];
}
int knapsack(int val[],int wt[],int n,int w){
    int ** dp = new int*[n];
    for(int i = 0 ; i < n ; i++){
        dp[i] = new int[W + 1];
    }
    memset(dp, -1, sizeof dp);
    return memo(wt,val,n,w,n-1,dp);
}
