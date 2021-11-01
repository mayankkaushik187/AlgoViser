//Leetcode 1482
class Solution {
    public:
        bool isFeasible(vector < int > & nums, int mid, int m, int k) {
            int flower = 0;
            for (int i = 0; i < nums.size();) {
                bool fl = false;
                int j;
                int count = 0;
                for (j = i; j < i + k and j < nums.size(); j++) {
                    if (nums[j] > mid) {
                        fl = true;
                        i = j + 1;
                        break;
                    }
                    count++;
                }
                if (!fl) {
                    if (count == k) flower++;
                    i = j;
                }
            }
            if (flower >= m) return true;
            else return false;
        }
    int minDays(vector < int > & bloomDay, int m, int k) {
        int low, high;
        if (m * k > bloomDay.size()) return -1;
        for (int i = 0; i < bloomDay.size(); i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while (low < high) {
            int mid = (low + high) / 2;
            if (isFeasible(bloomDay, mid, m, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
