class Solution {
public:
    bool predicate(vector<int>&piles,int mid,int h){
        int hours = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            if(piles[i] <= mid){
                hours++;
            }else{
                if(piles[i] % mid == 0){
                    hours += piles[i] / mid;
                }else{
                    hours += piles[i] / mid;
                    hours++;
                }
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        sort(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(predicate(piles,mid,h)){
                high = mid - 1;
                ans = mid;
                // [4,11,20,23,30]
                // [0  1  2  3  4]
                // []
            }else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};
