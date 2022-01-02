class Solution {
    public:
        int numPairsDivisibleBy60(vector < int > & time) {
            map < int, int > mp;
            int lenOfTime = time.size();
            for (int i = 0; i < lenOfTime; i++) {
                int key = time[i] % 60;
                mp[key]++;
            }
            int ans = 0;
            // for(auto &pair : mp){
            //     cout<<pair.first<<" : " << pair.second<<endl;
            // }
            for (auto[key, val]: mp) {
                int complement = 60 - key;
                if (mp.find(complement) != mp.end()) {
                    if (complement == 30) {
                        // cout<<val<<" faafasf";
                        ans += val * (val - 1) / 2;
                    } else {
                        ans += val * mp[complement];
                        mp[complement] = 0;
                    }
                    mp[key] = 0;
                } else {
                    if (complement == 60) {
                        ans += val * (val - 1) / 2;
                    }
                }
            }
            return ans;
        }
};
