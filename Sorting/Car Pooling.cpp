class Solution {
public:
    int passengers[1001] = {0};
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //merge intervals
        memset(passengers,0,sizeof passengers);
        int n = trips.size();
        for(int i = 0 ; i < n ; i++){
            passengers[trips[i][1]] += trips[i][0];
            passengers[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0 ; i < 1001 and capacity >= 0 ; i++){
            capacity -= passengers[i];
        }
        return capacity >= 0;
    }
};
