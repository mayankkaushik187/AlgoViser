//Leetcode 1456
class Solution {
    public:
        int maxVowels(string s, int k) {
            vector < int > vow = {
                1,
                0,
                0,
                0,
                1,
                0,
                0,
                0,
                1,
                0,
                0,
                0,
                0,
                0,
                1,
                0,
                0,
                0,
                0,
                0,
                1,
                0,
                0,
                0,
                0,
                0
            };
            int maxm = 0;
            int val = 0;
            for (int i = 0; i < s.size(); i++) {
                if (i < k) {
                    val += vow[s[i] - 'a'];
                }
                if (i >= k) {
                    val += vow[s[i] - 'a'];
                    val -= vow[s[i - k] - 'a'];
                }
                maxm = max(maxm, val);
            }
            return maxm;
        }
};
