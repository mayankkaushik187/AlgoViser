//Leetcode 1004
//Thinkable code
int longestOnes(vector < int > & nums, int k) {
  int i = 0;
  int maxlen = INT_MIN;
  int zeroCount = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] == 0) zeroCount++;
    while (zeroCount > k) {
      if (nums[i] == 0) zeroCount--;
      i++;
    }
    maxlen = max(maxlen, j - i + 1);
  }
  return maxlen;
}
//Elegant code
int longestOnes(vector < int > nums, int k) {
  int i = 0, j;
  for (j = 0; j < nums.size(); j++) {
    if (nums[j] == 0) k--;
    if (k < 0 and nums[i++] == 0) k++;
  }
  return j - i;
}
