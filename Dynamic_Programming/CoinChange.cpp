//Leetcode 322 

int coinChange(vector < int > & coins, int W) {
  int n = coins.size();
  vector < int > dp(W + 1, W + 1);
  dp[0] = 0;

  for (unsigned int i = 1; i <= W; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  return dp[W] > W ? -1 : dp[W];
}
