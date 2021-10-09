//leetcode - 90
 void helper(vector < int > & nums, vector < vector < int >> & res, vector < int > & temp, int index, vector < bool > & used) {
   res.push_back(temp);

   for (int i = index; i < nums.size(); i++) {
     if (used[i] || i > index and nums[i] == nums[i - 1] and!used[i - 1]) continue;//if the prev element in the sorted nums was same then we must have included all those sets which will be formed using this element already
     //the reason for this is that we are going in depth first search manner so when visualising using a euler tree the duplicate element will be processed always after the first occurence of that element as the array is sorted.
     temp.push_back(nums[i]);
     used[i] = true;
     helper(nums, res, temp, i + 1, used);
     temp.pop_back();
     used[i] = false;
   }
 }
 vector < vector < int >> subsetsWithDup(vector < int > & nums) {
   sort(nums.begin(), nums.end());
   vector < vector < int >> res;
   vector < int > temp;
   vector < bool > used(nums.size());
   helper(nums, res, temp, 0, used);

   return res;
 }
