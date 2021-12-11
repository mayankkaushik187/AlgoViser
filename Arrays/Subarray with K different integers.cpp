class Solution {
public:
    int helper(vector<int> &arr,int k){
        // unordered_set<int> st;
        unordered_map<int,int> mp;
        int res = 0;
        int n = arr.size();
        int j = 0;
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 1)count++;
            while(count > k){
                mp[arr[j]]--;
                if(mp[arr[j]] == 0)count--;
                j++;
            }
            res += i - j + 1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};
