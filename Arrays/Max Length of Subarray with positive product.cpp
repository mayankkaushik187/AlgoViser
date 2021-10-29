//Leetcode 1567
int getMaxLen(vector < int > & nums) {
    int positiveLen = 0;
    int negativeLen = 0;
    int ans = INT_MIN;
    for (int n: nums) {
        if (n == 0) {
            positiveLen = 0;
            negativeLen = 0;
        } else if (n > 0) {
            positiveLen++;
            negativeLen = negativeLen == 0 ? 0 : negativeLen + 1;
        } else if (n < 0) {
            int temp = positiveLen;
            positiveLen = negativeLen == 0 ? 0 : negativeLen + 1;
            negativeLen = temp + 1;
        }
        ans = max(ans, positiveLen);
    }
    return ans;
}
