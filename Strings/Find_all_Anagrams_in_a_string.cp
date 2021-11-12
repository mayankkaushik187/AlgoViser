class Solution {
public:
  //leetcode 483
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())return {};
        vector<int> res;
        map<char,int> p_count;
        for(auto x : p){
            p_count[x]++;
        }
        int j = 0;map<char,int> wind;
        for(int i = 0 ; i < s.size(); i++){
            wind[s[i]]++;
            if(i >= p.size()){
                wind[s[j]]--;
                if(wind[s[j]] == 0){
                    wind.erase(s[j]);
                }
                j++;
            }
            if(wind == p_count){
                res.push_back(j);
            }
        }
        return res;
    }
};
