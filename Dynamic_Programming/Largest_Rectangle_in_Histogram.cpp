class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> lessFromLeft(n,-1), lessFromRight(n,n);
        lessFromLeft[0] = -1;
        for(int i = 1 ; i < n ; i++){
            int j = i - 1;
            while(j >= 0 and arr[j] >= arr[i]){
                j = lessFromLeft[j];
            }
            lessFromLeft[i] = j;
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            int j = i + 1;
            while(j < n and arr[j] >= arr[i]){
                j = lessFromRight[j];
            }
            lessFromRight[i] = j;
        }
        int maxArea = 0;
        for(int i = 0 ; i  < n ; i++){
            maxArea = max(maxArea, arr[i] * (lessFromRight[i] - lessFromLeft[i] - 2 + 1));
        }
        return maxArea;
    }
};
