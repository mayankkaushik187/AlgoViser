//Leetcode- 1567
int getMaxLen(vector < int > & nums) {
  int firstNegative = -1;
  int zeroIndex = -1, negativeCount = 0;
  int maxLen = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      negativeCount++;
      if (firstNegative == -1) firstNegative = i;
    }

    if (nums[i] == 0) {
      zeroIndex = i;
      firstNegative = -1;
      negativeCount = 0;
    } else {
      if (negativeCount % 2 == 0) maxLen = max(i - zeroIndex, maxLen);
      else maxLen = max(i - firstNegative, maxLen);
    }
  }
  return maxLen;
}
