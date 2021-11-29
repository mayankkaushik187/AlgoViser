class Solution {
public:
//leetcode 976
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater());
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            if(nums[i] < nums[i+1] + nums[i+2]){
                return nums[i] + nums[i + 1] + nums[i+2];
            }
        }
        return 0;
    }
};
