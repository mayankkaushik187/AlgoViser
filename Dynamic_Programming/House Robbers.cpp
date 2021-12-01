//recursion O(2^N)TC O(N)SC
class Solution {
public:
    int helper(int n,int i,vector<int>&nums){
        if(n <= i){
            return 0;
        }
        int x = helper(n,i+2,nums) + nums[i];
        int y = helper(n,i+1,nums);
        return max(x,y);
    }
    int rob(vector<int>& nums) {
        //base case 
        int n = nums.size();
        if(n == 1)return nums[0];
        int i = 0;
        return helper(n,i,nums);
    }
};
//Memoized Soln O(n)TC O(n)SC
class Solution {
public:
    int memo[100005] = {-1};
    int helper(int n,int i,vector<int>&nums,vector<int> &dp){
        if(n <= i){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int x = helper(n,i+2,nums,dp) + nums[i];
        int y = helper(n,i+1,nums,dp);
        return dp[i] = max(x,y);
    }
    int rob(vector<int>& nums) {
        //base case 
        int n = nums.size();
        if(n == 1)return nums[0];
        int i = 0;
        vector<int> dp(n,-1);
        return helper(n,i,nums,dp);
    }
};
//tabulated O(n)TC O(n)SC
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[1],nums[0]);
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i = 2; i < n ;i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
//dp with two vars
//O(n)TC and O(1)SC
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[1],nums[0]);
        int prev1 = max(nums[1],nums[0]);
        int prev2 = nums[0];
        int ans = 0;
        for(int i = 2; i < n ; i++){
            ans = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};

