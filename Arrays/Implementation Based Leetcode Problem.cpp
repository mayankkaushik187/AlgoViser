class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> res;
        int minm = INT_MAX;
        for(int i = 0 ; i < n - 1 ; i++){
            if(arr[i + 1] - arr[i] < minm){
                res.clear();
                res.push_back({arr[i],arr[i+1]});
                minm = min(minm,arr[i+1] - arr[i]);
            }else if(arr[i + 1] - arr[i] == minm){
                // cout<<"asdas";
               res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};
