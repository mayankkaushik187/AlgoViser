class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> mp;
        for(int i : s){
            mp.insert(i);
        }
        int count = 0;
        for(int i = 0 ; i < g.size() ; i++){
            auto it = mp.lower_bound(g[i]);
            if(it!=mp.end()){
                mp.erase(it);
                count++;
            }
        }
        return count;
    }
};
