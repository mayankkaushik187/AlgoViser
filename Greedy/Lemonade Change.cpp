class Solution {
public:
	//O(n)time ans O(1) space
	bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int money = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            if(bills[i] == 10){
                if(mp[5] == 0)return false;
                mp[5]--;
            }else if(bills[i] == 20){
                if(mp[10] >= 1 and mp[5] >= 1){
                    mp[10]--;
                    mp[5]--;
                }else if(mp[5] >= 3){
                    mp[5] -= 3;
                }else{
                    return false;
                }
            }
            mp[bills[i]]++;
        }
        return true;
    }
};
//leetcode 860
