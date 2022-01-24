class Solution {
public:
    int maximumGood(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = INT_MIN;
        for(int x = 0 ; x < 1 << n ; x++){
            bool fl = true;
            for(int i = 0 ; i < n ; i++){
                if(!(x & (1 << i)))
                    continue;
                for(int j = 0 ; j < n ; j++){
                    if(arr[i][j] == 1){
                        if(!(x & (1 << j))){
                            fl = false;
                        }
                    }
                    if(arr[i][j] == 0){
                        if(x & (1 << j)){
                            fl = false;
                        }
                    }
                }
            }
            if(fl){
                int count = 0;
                for(int i = 0 ; i < 16 ; i++){
                    if(x & (1 << i))count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
