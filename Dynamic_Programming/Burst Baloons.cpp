class Solution {
public:
    int n;
    int memo[1000][1000];
    int helper(vector<int>&nums,int i,int j){
        if(i > j)return 0;
        if(i == j){
            int temp = nums[i];
            if(i - 1 >= 0){
                temp *= nums[i - 1];
            }
            if(i + 1 < n){
                temp *= nums[i + 1];    
            }
            return temp;
        }
        if(memo[i][j] != -1)return memo[i][j];
        int best = INT_MIN;
        for(int id = i ; id <= j ; id++){
            int temp = nums[id];
            if(i - 1 >= 0){
                temp *= nums[i - 1];
            }
            if(j + 1 < n){
                temp *= nums[j + 1];
            }
            temp += helper(nums,i, id - 1) + helper(nums, id + 1,j);
            
            best = max(best , temp);
        }
        memo[i][j] = best;
        return best;
    }
    int maxCoins(vector<int>& nums) {
        memset(memo,-1,sizeof memo);
        vector<int> arr = {1};
        for(int &x : nums){
            arr.push_back(x);
        }
        arr.push_back(1);
        n = arr.size();
        return helper(arr,1, n - 2);
    }
};
