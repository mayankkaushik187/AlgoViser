class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum = 0;
            for(int j = i ; j < nums.size() ; j++){
                sum += nums[j];
                res.push_back(sum);
            }
        }
        const int mod = 1e9 + 7;
        sort(res.begin(),res.end());
        int ans = 0;
        for(int i = left - 1; i < right ; i++){
            ans = (ans + res[i])%mod;
        }
        return (int)ans % mod;
    }
};
