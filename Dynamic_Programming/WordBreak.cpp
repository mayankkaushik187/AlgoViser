//leetcode 139

bool helper(string s, unordered_set < string > & st) {

    int n = s.size();
    vector < unsigned int > dp(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            string check = s.substr(j, i - j + 1);
            if (st.find(check) != st.end()) {
                if (j > 0) {
                    dp[i] += dp[j - 1];
                } else {
                    dp[i] += 1;
                }
            }
        }
    }
    return dp[n - 1] != 0;

}
bool wordBreak(string s, vector < string > & wordDict) {
    unordered_set < string > st;
    for (int i = 0; i < wordDict.size(); i++) {
        st.insert(wordDict[i]);
    }
    return helper(s, st);
}
