#include<bits/stdc++.h>
using namespace std;
//Leetcode --- 740
int deleteAndEarn(vector < int > & nums) {
   int n = 1e4 + 1;
   vector < int > dp(n, 0), sum(n, 0); //dp[i] means what is the sum of points when we use i
   //2,2,2,2,4,3
   //sum[2] = 8;
   //sum[4] = 4;
   /*
   sum[3] = 3;
   */
   for (auto x: nums) {
     sum[x] += x;
   }

   dp[0] = 0;
   dp[1] = sum[1];
   for (int i = 2; i < n; i++) {
     dp[i] = max(dp[i - 1], sum[i] + dp[i - 2]);
   }

   return dp[n - 1];
}
