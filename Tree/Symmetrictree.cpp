//Leetcode 101
bool isMirror(TreeNode * root1, TreeNode * root2) {
    if (!root1 and!root2) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }

    return root1 -> val == root2 -> val and isMirror(root1 -> left, root2 -> right) and isMirror(root1 -> right, root2 -> left);
}
bool isSymmetric(TreeNode * root) {
    if (!root) {
        return true;
    }
    return isMirror(root -> left, root -> right);
}
