//Leetcoded 329
int dfs(vector < vector < int >> & dp, vector < vector < int >> & matrix, int x, int y, int n, int m) {
    if (dp[x][y]) return dp[x][y];
    vector < vector < int >> dirs = {
        {
            1,
            0
        },
        {
            0,
            1
        },
        {
            -1,
            0
        },
        {
            0,
            -1
        }
    };
    for (auto dir: dirs) {
        int xx = x + dir[0], yy = y + dir[1];
        if (xx >= n or xx < 0 or yy >= m or yy < 0) continue;
        if (matrix[xx][yy] <= matrix[x][y]) continue;
        dp[x][y] = max(dp[x][y], dfs(dp, matrix, xx, yy, n, m));
    }
    return ++dp[x][y];
}
int longestIncreasingPath(vector < vector < int >> & matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    vector < vector < int >> dp(n, vector < int > (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(dp, matrix, i, j, n, m));
        }
    }
    return ans;

}
