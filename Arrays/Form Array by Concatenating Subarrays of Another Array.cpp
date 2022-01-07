class Solution {
public:
    pair<int,int> search(vector<int>&temp,vector<int>&nums,int prevEnd){
        int size = temp.size();
        int n = nums.size();
        pair<int,int> ans = {-1,-1};
        int i;
        if(prevEnd == -1){
            i = 0;
        }else{
            i = prevEnd;
        }
        for(; i < n - size + 1 ; i++){
            int i_ = i;
            bool found = true;
            for(int j = 0 ; j < size ;){
                if(temp[j] == nums[i_]){
                    j++;
                    i_++;
                }else{
                    found = false;
                    break;
                }
            }
            if(found){
                ans.first = i;
                ans.second = i + size - 1;
                
                return ans;
            }
        }
        
        return ans;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int prevEnd = -1;
        int prevStart = -1;
        for(int i = 0 ; i < n ; i++){
            auto temp = groups[i];
            auto indexes = search(temp,nums,prevEnd);
            if(indexes.first == -1){
                return false;
            }
            if(prevEnd >= indexes.first){
                return false;
            }
            prevStart = indexes.first;
            prevEnd = indexes.second;
        }
        
        return true;
    }
};
