//Recursive
//o(2^n) - TC
class Solution {
public:
    int helper(vector<int>&arr,int index,int n,int time){
        if(index == n){
            return 0;
        }
        int x = arr[index] * time + helper(arr,index + 1,n,time + 1);
        int y = helper(arr,index + 1,n,time);
        
        
        return max(x,y);
        
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return helper(arr,0,arr.size(),1);
    }
};

//Memoised
//O(n^2) - TC
class Solution {
public:
    int memo[501][501];
    int helper(vector<int>&arr,int index,int n,int time){
        if(index == n){
            return 0;
        }
        if(memo[index][time] != -1)return memo[index][time];
        int x = arr[index] * time + helper(arr,index + 1,n,time + 1);
        int y = helper(arr,index + 1,n,time);
        
        memo[index][time] = max(x,y);
        return max(x,y);
        
    }
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < 501 ; i++){
            for(int j = 0 ; j < 501 ; j++){
                memo[i][j] = -1;
            }
        }
        return helper(arr,0,arr.size(),1);
    }
};


//Bottom Up
//O(n^2)
class Solution {
public:
    const int INF = -1e5;
    int dp[501][501] = {INF};
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        int maxm = INT_MIN;
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i <= n; i++){
            dp[n][i] = 0;
        }
        for(int i = n - 1; i >= 0 ; i--){
            for(int j = 1 ; j <= n ; j++){
                dp[i][j] = max(dp[i+1][j],dp[i+1][j+1] + arr[i] * j);
            }
        }
        return dp[0][1];
    }
};

//Greedy 
//O(nlogn)
class Solution {
public:
    
    int maxSatisfaction(vector<int>& arr) {
        int res = 0;
        int pre = 0;
        int curr = 0;
        sort(arr.begin(),arr.end(),greater<int>());
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            pre += arr[i];
            curr += pre;
            res = max(res,curr);
        }
        
        return res;
    }
};
