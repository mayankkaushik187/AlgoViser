//Leetcode 1448
void helper(TreeNode * root, vector < int > & res, int prev) {
  if (!root) return;
  if (root -> val >= prev) {
    res.push_back(root -> val);
    prev = max(prev, root -> val);
  }
  helper(root -> left, res, prev);
  helper(root -> right, res, prev);
}
int goodNodes(TreeNode * root) {
  if (!root) return 0;
  vector < int > res;
  int prev = INT_MIN;
  helper(root, res, prev);
  for (int i: res) cout << i << " ";
  return res.size();
}
