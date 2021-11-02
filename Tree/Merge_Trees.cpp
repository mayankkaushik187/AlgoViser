//Leetcode 617
class Solution {
    public:
        TreeNode * mergeTrees(TreeNode * t1, TreeNode * t2) {
            if (!t1) return t2;
            if (!t2) return t1;

            TreeNode * newRoot = new TreeNode(t1 -> val + t2 -> val);
            newRoot -> left = mergeTrees(t1 -> left, t2 -> left);
            newRoot -> right = mergeTrees(t1 -> right, t2 -> right);

            return newRoot;
        }
};
