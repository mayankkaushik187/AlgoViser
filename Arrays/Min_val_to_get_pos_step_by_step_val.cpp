class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            mn = min(mn,sum);
        }
        return mn > 0 ? 1 : abs(mn) + 1;
    }
};
