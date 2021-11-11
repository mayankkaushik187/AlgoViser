//leetcode 986

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res;
        int i = 0 , j = 0;
        while(i < a.size() and j < b.size()){
            int a_start = a[i][0], b_start = b[j][0];
            int a_end = a[i][1], b_end = b[j][1];
            if(a_start <= b_end and b_start <= a_end){
                res.push_back({max(a_start,b_start),min(a_end,b_end)});
            }
            if(a_end <= b_end){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
