//Leetcode 15
//while loops remove the duplicates a 
class Solution {
  public:
    vector < vector < int >> threeSum(vector < int > & nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector < vector < int >> res;
      for (int i = 0; i < n - 2; i++) {
        int low = i + 1, high = n - 1;
        while (i + 1 < n and nums[i] == nums[i + 1]) {
          i++;
          continue;
        }
        while (low < high) {
          if (nums[i] + nums[low] + nums[high] == 0) {
            while (low + 1 < n and nums[low] == nums[low + 1]) {
              low++;
              continue;
            }
            while (high - 1 >= 0 and nums[high] == nums[high - 1]) {
              high--;
              continue;
            }
            res.push_back({
              nums[i],
              nums[low],
              nums[high]
            });
            low++;
            high--;
          } else if (nums[i] + nums[low] + nums[high] > 0) {
            while (high - 1 >= 0 and nums[high] == nums[high - 1]) {
              high--;
              continue;
            }
            high--;
          } else {
            while (low + 1 < n and nums[low] == nums[low + 1]) {
              low++;
              continue;
            }
            low++;
          }
        }
      }
      return res;
    }
};
