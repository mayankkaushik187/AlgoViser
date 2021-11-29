class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> nums;
        for(int i = 0 ; i < s.size() + 1;i++){
            nums.push_back(i);
        }
        vector<int> res;
        int i = 0;
        int d = nums.size() - 1;
        for(int x = 0 ; x < s.size() ; x++){
            if(s[x] == 'I'){
                res.push_back(nums[i++]);
            }else{
                res.push_back(nums[d--]);
            }
        }
        res.push_back(nums[i]);
        return res;
    }
};
//leetcode 942
