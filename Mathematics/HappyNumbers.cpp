//Leetcode -- 202
int getNext(int n) {
  int res = 0;
  while (n > 0) {
    int digit = n % 10;
    res += digit * digit;
    n = n / 10;
  }
  return res;
}
bool isHappy(int n) {
  int fast_p = getNext(n);
  int slow_p = n;

  while (fast_p != 1 and fast_p != slow_p) {
    slow_p = getNext(slow_p);
    fast_p = getNext(getNext(fast_p));
  }

  return fast_p == 1;
}
