class Solution {
public:
    //Leetcode 220
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        long val ;
        for(int i = 0 ; i < nums.size() ; i++){
            val = (long)nums[i];
            if(i > k)window.erase(nums[i - k -1]);
            auto pos = window.lower_bound(val - t);
            if(pos != window.end() and *pos - nums[i] <= t)return true;
            window.insert(val);
        }
        return false;
    }
};
