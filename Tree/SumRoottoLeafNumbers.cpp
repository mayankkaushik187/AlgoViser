//Leetcode 129
int helper(TreeNode * root, int sum) {
    if (!root) return 0;
    if (!root -> left and!root -> right) return sum * 10 + root -> val;
    return helper(root -> left, sum * 10 + root -> val) + helper(root -> right, sum * 10 + root -> val);
}
int sumNumbers(TreeNode * root) {
    return helper(root, 0);
}
