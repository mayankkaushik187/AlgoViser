//LeetCode - 47

void helper(vector < vector < int >> & res, vector < int > & temp, vector < bool > & isPresent, vector < int > & nums) {
  if (temp.size() == nums.size()) {
    res.push_back(temp);
    return;
  } else {
    for (int i = 0; i < nums.size(); i++) {
      if (isPresent[i] || i > 0 and nums[i] == nums[i - 1] and!isPresent[i - 1]) continue;
      else {
        isPresent[i] = true;
        temp.push_back(nums[i]);
        helper(res, temp, isPresent, nums);
        temp.pop_back();
        isPresent[i] = false;
      }
    }
  }
}
vector < vector < int >> permuteUnique(vector < int > & nums) {
    sort(nums.begin(), nums.end());
    vector < int > temp;
    vector < vector < int >> res;
    vector < bool > isPresent(nums.size());
    helper(res, temp, isPresent, nums);
    return res; 
}
