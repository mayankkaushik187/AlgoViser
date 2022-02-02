class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())return {};
        vector<int> res;
        map<char,int> mp;
        for(auto &ch : p)
            mp[ch]++;
        int j = 0;
        map<char,int> temp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            temp[s[i]]++;
            if(i >= p.size()){
                temp[s[j]]--;
                if(temp[s[j]] == 0){
                    temp.erase(s[j]);
                }
                j++;
            }
            if(temp == mp){
                res.push_back(j);
            }
        }
        return res;
    }
};
