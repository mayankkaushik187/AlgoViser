//Leetcode 30
class Solution {
public:
    //TC - O(s.size()*words[i].size()*words.size()) = O(n*len) where n is s.size()
    //SC - O(words.size())
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> count;
        for(auto x : words)count[x]++;
        vector<int> res;
        int len = words.size() * words[0].size();
        if(len > s.size())return res;
        for(int i = 0 ; i <= s.size() - len ; i++){
            unordered_map<string,int> seen;
            int j;
            for(j = 0 ; j < len ; j += words[0].size()){
                string str = s.substr(i + j, words[0].size());
                if(count.find(str)!=count.end()){
                    seen[str]++;
                    if(seen[str] > count[str])break;
                }else break;
            }
            if(j == len)res.push_back(i);
        }
        return res;
    }
};
