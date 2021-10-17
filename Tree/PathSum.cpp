//Leetcode 437

int count = 0;

 void helper(TreeNode * root, int targetSum) {
   if (!root) return;
   if (root -> val == targetSum) count++;
   helper(root -> left, targetSum - root -> val);
   helper(root -> right, targetSum - root -> val);
 }
 int pathSum(TreeNode * root, int targetSum) {
   if (root) {
     helper(root, targetSum);
     pathSum(root -> left, targetSum);
     pathSum(root -> right, targetSum);
   }
   return count;
 }
