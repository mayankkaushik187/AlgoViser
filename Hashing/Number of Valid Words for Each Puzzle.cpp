class Solution {
public:
    int genSubMasks(string&s){
        int res = 0;
        for(auto c : s){
            res |= 1 << c - 'a';
        }
        return res;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> mp;
        for(auto x : words){
            mp[genSubMasks(x)]++;
        }
        vector<int> res(puzzles.size());
        int i = 0;
        for(auto p : puzzles){
            int mask = genSubMasks(p), ans = 0, first = 1 << p[0] - 'a';
            for(int submask = mask ; submask; submask = (submask - 1) & mask){
                if(submask & first){
                    ans += mp[submask];
                }
            }
            res[i++] = ans;
        }
        return res;
    }
};
