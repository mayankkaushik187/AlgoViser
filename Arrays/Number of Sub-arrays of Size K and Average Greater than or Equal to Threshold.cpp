//Leetcode 1343
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += arr[i];
        }
        int count = 0;
        if(sum / k >= threshold){
            count++;
        }
        for(int i = k; i < n ; i++){
            sum += arr[i] - arr[i-k];
            count += sum/k >= threshold ? 1 : 0;
        }
        return count;
    }
};
