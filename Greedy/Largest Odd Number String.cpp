class Solution {
public:
    //O(n) time and O(n) space;
    string largestOddNumber(string num) {
        int n = num.size();
        string res = "";
        int maxSize = 0;
        string ans;
        for (int i = 0 ; i < n ; i++) {
            res += num[i];
            if ((num[i] - '0') % 2 == 1) {
                if (maxSize < res.size()) {
                    maxSize = res.size();
                    ans = res;
                }
            }
        }
        return maxSize == 0 ? "" : ans;
    }
    //O(n) time ans O(1) space
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n - 1;
        while (i >= 0) {
            if (num[i] - '0' % 2 == 1)break;
            i--;
        }
        return i < 0 ? "" : num.substr(0, i + 1);
    }
};
//leetcode 1903
