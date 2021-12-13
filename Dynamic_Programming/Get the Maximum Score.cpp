class Solution {
public:
    vector<int> nums1,nums2;
    int n,m;
    map<int,int> mp1,mp2;
    long long int dp[100001][2];
    const int MOD = 1e9 + 7;
private:
    long long int helper(int index,int toggle){
        if(toggle and index >= n)return 0;
        if(!toggle and index >= m)return 0;
        
        if(dp[index][toggle] != -1)return dp[index][toggle];
        
        if(toggle){
            if(mp2[nums1[index]]){
                dp[index][toggle] = max(helper(mp2[nums1[index]],toggle ^ 1) + nums1[index],nums1[index] + helper(index + 1,toggle));
            }else{
                dp[index][toggle] = (long long int)(nums1[index] + helper(index + 1,toggle));
            }
        }else{
            if(mp1[nums2[index]]){
                dp[index][toggle] = max(helper(mp1[nums2[index]],toggle ^ 1) + nums2[index],nums2[index] + helper(index + 1,toggle));
            }else{
                dp[index][toggle] = (long long int)(nums2[index] + helper(index +1 ,toggle));
            }
        }
        return dp[index][toggle];
    }        
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        memset(dp,-1,sizeof dp);
        for(int i = 0 ; i < n ; i++){
            mp1[nums1[i]] = i + 1;
        }
        for(int i = 0 ; i < m ; i++){
            mp2[nums2[i]] = i + 1;
        }
        
        long long int ans = max(helper(0,1),helper(0,0));
        return ans % MOD;
    }
};
