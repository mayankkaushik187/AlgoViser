class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)return false;
        int n = arr.size();
        int first = 0, second = n - 1;
        while(first < second){
            if(arr[first] < arr[first + 1])first++;
            else if(arr[second] < arr[second - 1])second--;
            else break;
        }
        return first > 0 and second < n - 1 and first == second;
    }
};
