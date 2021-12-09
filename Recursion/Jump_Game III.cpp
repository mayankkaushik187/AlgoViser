class Solution {
public:
    
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 or start >= arr.size() or arr[start] < 0){
            return false;
        }
        arr[start] = -arr[start];
        return arr[start] == 0 or canReach(arr, start - arr[start]) or canReach(arr,start + arr[start]);
    }
};
