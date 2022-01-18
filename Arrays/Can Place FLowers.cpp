class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        unordered_map<int,multiset<int>> mp;
        
        for(int i = 0 ; i < int(arr.size()) ; i++){
            if(arr[i] == 1)mp[arr[i]].insert(i);
        }
        
        for(int i = 0 ; i < int(arr.size()) ; i++){
            if(arr[i] == 0){
                if(mp[1].find(i - 1) == mp[1].end() and mp[1].find(i + 1) == mp[1].end()){
                    n--;
                    mp[1].insert(i);
                }
            }
        }
        return n <= 0;
    }
};
