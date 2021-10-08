//leetcode 191
int hammingWeight(uint32_t n) {
    bitset < 32 > bs(n);
    int count = 0;
    for (int i = 0; i < 32; i++) {
      if (bs[i] == 1) {
        count++;
      }
    }
    return count;
}
