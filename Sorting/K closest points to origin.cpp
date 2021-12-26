class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>> ,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>> > pq;
        int n = points.size();
        for(int i = 0; i < n ; i++){
            int val = abs(points[i][0]) * abs(points[i][0]) + abs(points[i][1]) * abs(points[i][1]);
            pq.push({val,{points[i][0],points[i][1]}});
        }
        
        vector<vector<int>> res;
        for(int i = 0 ; i < k ; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
