class Solution {
public:
    //leetcode 56
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        sort(intervals.begin(),intervals.end(),[&](const vector<int>&a,const vector<int>&b){
            if(a[0] == b[0])return a[1] < b[1];
            return a[0] < b[0];  
        });
        vector<vector<int>> res;
        res.push_back({intervals[0][0],intervals[0][1]});
        for(int i = 1 ; i < n ; i++){
            int prevStart = res[res.size() - 1][0];
            int prevEnd = res[res.size() - 1][1];
            if(intervals[i][0] <= prevEnd){
                res.pop_back();
                res.push_back({min(intervals[i][0],prevStart),max(prevEnd,intervals[i][1])});
            }else{
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        
        return res;
    }
};
