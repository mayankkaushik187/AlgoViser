// Give the function a bound the maximum number it will handle.
// The left recursion will take the elements smaller than node.val
// The right recursion will take the remaining elements smaller than bound

// Complexity
// bstFromPreorder is called exactly N times.
// It's same as a preorder traversal.
// Time O(N)
// Space O(H)

//LEETCODE - 1008
int i = 0;

TreeNode * construct(vector < int > & preorder, int bound = INT_MAX) {
  if (preorder.size() == i || preorder[i] > bound) return NULL;
  TreeNode * root = new TreeNode(preorder[i++]);
  root -> left = construct(preorder, root -> val);
  root -> right = construct(preorder, bound);
  return root;
}
TreeNode * bstFromPreorder(vector < int > & preorder) {
  TreeNode * root = new TreeNode(0);
  root = construct(preorder);

  return root;
}
