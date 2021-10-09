//Leetcode 78
void helper(vector < vector < int >> & res, vector < int > & temp, vector < int > & nums, int index) {
  res.push_back(temp);
  for (int i = index; i < nums.size(); i++) {
    temp.push_back(nums[i]);
    helper(res, temp, nums, i + 1);
    temp.pop_back();
  }

}
vector < vector < int >> subsets(vector < int > & nums) {
  vector < vector < int >> res;
  vector < int > temp;
  sort(nums.begin(), nums.end());
  helper(res, temp, nums, 0);

  return res;
}
