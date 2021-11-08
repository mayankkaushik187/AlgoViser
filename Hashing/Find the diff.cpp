//Leetcode 389
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        for(int i = 0 ; i < t.size() ; i++){
            mp[t[i]]++;
        }
        for(int i = 0 ;i < s.size() ; i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
            }
        }
        char ans;
        for(auto x : mp){
            ans = x.first;
        }
        return ans;
    }
};
