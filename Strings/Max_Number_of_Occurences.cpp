//Leetcode 1297
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> occ_map;
        int cnt[26] = {0},res = 0,i = 0, j = 0,unique = 0; 
        while(j < s.size()){
            if(cnt[s[j] - 'a']++ == 0)unique++;
            while(unique > maxLetters or j - i + 1 > minSize){
                if(cnt[s[i] - 'a']-- == 1)unique--;
                i++;
            }
            if(j - i + 1 == minSize) res = max(res,++occ_map[s.substr(i,minSize)]);
            j++;
        }
        return res;
    }
};
