class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        int start = -1,end = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(arr[i] != nums[i]){
                start = i;
                break;
            }
        }
        int n = nums.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            if(arr[i] != nums[i]){
                end = i;
                break;
            }
        }
        return start == -1 ? 0 : end - start + 1;
    }
};
