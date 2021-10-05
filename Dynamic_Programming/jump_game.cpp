/*
leetcode -- 55
The idea is to use keep checking throughout the array and whenever we find a cond. against our critteria then we will return else we would have travelled till n - 1th element and after for loop increments it we will be at nth index;
and if so just return true;

*/

bool canJump(vector<int>& nums) {
  int n = nums.size();
  int i = 0 ,reach = 0;
  
  for(; i < n ; i++){
    if(reach < i)return false;
    
    reach = max(reach,i + nums[i]);
  }
  
  return i == n;
}
