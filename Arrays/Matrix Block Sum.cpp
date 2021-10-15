//Leetcode 1314

vector < vector < int >> matrixBlockSum(vector < vector < int >> & mat, int k) {
  int n = mat.size();
  int m = mat[0].size();

  int sum[n + 1][m + 1];
  memset(sum, 0, sizeof sum);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + mat[i - 1][j - 1] - sum[i - 1][j - 1];
    }
  }

  vector < vector < int >> res(n, vector < int > (m));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      int r1 = max(0, r - k);
      int r2 = min(n - 1, r + k);
      int c1 = max(0, c - k);
      int c2 = min(m - 1, c + k);
      r1++;
      r2++;
      c1++;
      c2++;

      res[r][c] = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    }
  }

  return res;
}
