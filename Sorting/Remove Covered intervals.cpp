class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });
        int covered_intervals = 0, maximum_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maximum_end) {
                covered_intervals++;
            }
            maximum_end = max(maximum_end, intervals[i][1]);
        }
        return intervals.size() - covered_intervals;
    }
};
