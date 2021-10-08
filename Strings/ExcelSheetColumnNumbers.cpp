//leetcode - 171
int titleToNumber(string columnTitle) {
  unordered_map < char, int > hsh;
  //"ABC" - 1 * 26**n-0-1 + 2 * 26 ** n - 1 - 1 + 3 * 26** n-2-1 
  for (int i = 0; i < 26; i++) {
    hsh.insert({
      (char)(i + 65),
      i + 1
    });
  }
  int ans = 0;
  int n = columnTitle.size();
  for (int i = 0; i < n; i++) {
    ans += hsh[columnTitle[i]] * pow(26, n - i - 1);
  }
  return ans;

}
