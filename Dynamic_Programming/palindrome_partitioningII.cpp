class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n,vector<bool>(n,false));
        vector<int> cut(n,0);

        for(int i = 0; i < n; i++) {
            int minm = i;
            for(int j = 0; j <= i; j++) {
                if(s[j] == s[i] && (j + 1 > i - 1 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;  
                    minm = j == 0 ? 0 : min(minm, cut[j - 1] + 1);
                }
            }
            cut[i] = minm;
        }
        return cut[n - 1];
    }
};
