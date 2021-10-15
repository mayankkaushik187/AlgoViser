//Leetcode 63a
int uniquePathsWithObstacles(vector < vector < int >> & obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[m][n];
    memset(dp, 0, sizeof dp);
    dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 1; i < m; i++) {
        dp[i][0] = !obstacleGrid[i][0] ? dp[i - 1][0] : 0;
    }
    for (int i = 1; i < n; i++) {
        dp[0][i] = !obstacleGrid[0][i] ? dp[0][i - 1] : 0;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}
