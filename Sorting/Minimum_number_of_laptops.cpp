class Solution {
    public:
        // static bool mycomp(pair<int,int>&p1,pair<int,int>&p2){
        //     if(p1.first == p2.first){
        //         return p1.first < p2.second;
        //     }
        //     return p1.first < p2.first;
        // }
        // int solve(vector<pair<int,int>>&arr){
        //     int laps = 1;
        //     int res = 0;
        //     int maxLaps = 1;
        //     for(int i = 1 ; i < arr.size() ; i++){
        //         if(arr[i].first < arr[res].second){
        //             laps++;
        //             maxLaps = max(laps,maxLaps);
        //             continue;
        //         }else{

        //         }

        //     }

        //     return maxLaps;
        // }
        int minLaptops(int n, int start[], int end[]) {
            // if(n == 1){
            //     return 1;
            // }
            // vector<pair<int,int>> arr;
            // for(int i = 0 ; i < n ; i++)
            // {
            //     arr.push_back({start[i],end[i]});
            // }
            // sort(arr.begin(),arr.end(),mycomp);

            // return solve(arr);
            sort(start, start + n);
            sort(end, end + n);

            int laps = 1;
            int res = 1;
            int i = 1;
            int j = 0;
            while (i < n and j < n) {
                if (start[i] < end[j]) {
                    laps++;
                    i++;
                } else {
                    laps--;
                    j++;
                }
                if (laps > res) {
                    res = laps;
                }
            }

            return res;

        }
};
