class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int ans =0 ;
        map<int,int> mp;
        for(int i= 0 ; i < n ; i++){
            ans += (prefix[i] == goal);
            if(mp.find(prefix[i] - goal) != mp.end()){
                ans += mp[prefix[i] - goal];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
    
};
