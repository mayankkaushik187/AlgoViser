class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> index;
        for(int i = 0 ; i < int(seats.size()) ; i++){
            if(seats[i]){
                index.push_back(i);
            }
        }
        int m = seats.size();
        int n = index.size();
        int maxm = INT_MIN;
        maxm = max(maxm,index[0] - 0);
        maxm = max(maxm,m - index[n - 1] - 1);
        
        int start = index[0] + 1;
        int end = index[n - 1] - 1;
        if(end < start){
            return maxm;
        }
        for(int i = start ; i <= end ; i++){
            auto closest = upper_bound(index.begin(),index.end(),i);
            int val = *closest - i;
            closest--;
            int close = min(val,i - *closest);
            maxm = max(maxm,close);
        }
        
        return maxm;
    }
};
