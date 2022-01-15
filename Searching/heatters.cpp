class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        int m = houses.size();
        sort(heaters.begin(),heaters.end());
        int maxm = INT_MIN;
        for(int house : houses){
            auto close = lower_bound(heaters.begin(),heaters.end(),house);
            int ans1 = INT_MAX;
            if(close != heaters.end()){
                ans1 = min(ans1,*close - house);
            }
            if(close != heaters.begin()){
                close--;
                ans1 = min(ans1,house - *close);
            }
            maxm = max(ans1,maxm);
        }
        return maxm;
    }
};
