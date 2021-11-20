class Solution {
public:
  //leetcode 540
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(mid & 1)mid--;
            if(nums[mid] != nums[mid + 1]){
                r = mid;
            }else{
                l = mid + 2;
            }
        }
        return nums[l];
    }
};
