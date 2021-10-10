class Solution {
    public://leetcode 131
        bool isPalindrome(string s, int i, int j) {
            while (i < j) {
                if (s[i++] != s[j--]) {
                    return false;
                }
            }

            return true;
        }
    void dfs(vector < vector < string >> & res, string s, int start, vector < string > & curr) {
        if (start >= s.size()) {
            res.push_back(curr);

            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));
                dfs(res, s, i + 1, curr);
                curr.pop_back();
            }
        }
    }
    vector < vector < string >> partition(string s) {
        vector < vector < string >> res;

        vector < string > curr;
        dfs(res, s, 0, curr);
        return res;
    }
};
