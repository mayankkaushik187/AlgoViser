class Solution {
public:
  //leetcode 713
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int n = nums.size();
        int j = 0;
        if(k == 0)return 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            prod *= nums[i];
            while(i >= j and prod >= k){
                prod /= nums[j];
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
};
