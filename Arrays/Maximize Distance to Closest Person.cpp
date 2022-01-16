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
//O(1) space
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = INT_MIN;
        int last = -1;
        int n = seats.size();
        for(int i = 0 ; i < n ; i++){
            if(seats[i]){
                res = last < 0 ? i : max(res,(i - last) / 2);
                last = i;
            }
        }
        
        res = max(res, n - 1 - last);
        return res;
    }
};
