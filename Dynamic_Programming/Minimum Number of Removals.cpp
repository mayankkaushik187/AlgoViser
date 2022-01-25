//LC 1671
class Solution {
public:
    int n;
    int minimumMountainRemovals(vector<int>& arr) {
        n = arr.size();
        vector<int> dp_l(n,1),dp_r(n,1);
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i] > arr[j]){
                    dp_l[i] = max(dp_l[i], dp_l[j] + 1);
                }
            }
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = n - 1 ; j > i ; j--){
                if(arr[i] > arr[j]){
                    dp_r[i] = max(dp_r[i], dp_r[j] + 1);
                }
            }
        }
        int maxm = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            if(dp_l[i] > 1 and dp_r[i] > 1){
                maxm = max(maxm, dp_l[i]  + dp_r[i] - 1);
            }
        }
        return n - maxm;
    }
    
};
