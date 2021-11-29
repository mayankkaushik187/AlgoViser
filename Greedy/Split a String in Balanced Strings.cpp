//leetcode 1221
class Solution {
public:
    int balancedStringSplit(string s) {
        int i = 0,count = 0;
        int ans = 0;
        while(i < s.size()){
            if(s[i++] == 'R'){
                count++;
            }else{
                count--;
            }
            if(count == 0)ans++;
        }
        return ans;
    }
};
