//leetcode - 46
void helper(vector < vector < int >> & res, vector < int > & nums, vector < int > & temp, unordered_set < int > & s) {
  if (temp.size() == nums.size()) {
    res.push_back(temp);
    return;
  } else {
    for (int i = 0; i < nums.size(); i++) {
      if (s.find(nums[i]) != s.end()) continue;
      temp.push_back(nums[i]);
      s.insert(nums[i]);
      helper(res, nums, temp, s);
      temp.pop_back();
      s.erase(nums[i]);
    }
  }
}
vector < vector < int >> permute(vector < int > & nums) {
  vector < vector < int >> res;

  vector < int > temp;
  unordered_set < int > s;
  helper(res, nums, temp, s);

  return res;
}
