//Leetcode 10
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector < vector < bool >> dp(m + 1, vector < bool > (n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (j == 0) {
                if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];
                } else {
                    dp[i][j] = false;
                }
            } else {
                char patChar = p[i - 1];
                char strChar = s[j - 1];

                if (patChar == '*') {
                    dp[i][j] = dp[i - 2][j];
                    char lastSecCharPat = p[i - 2];
                    if (lastSecCharPat == '.' || lastSecCharPat == strChar) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                } else if (patChar == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (patChar == strChar) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[m][n];
}
