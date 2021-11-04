/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //leetcode 404
class Solution {
    public:
        int sum = 0;
    void helper(TreeNode * root, bool left) {
        if (!root) return;
        if (!root -> left and!root -> right and left == true) {
            sum += root -> val;
            return;
        }
        helper(root -> left, true);
        helper(root -> right, false);
    }
    int sumOfLeftLeaves(TreeNode * root) {
        if (!root) return 0;
        helper(root, false);
        return sum;
    }
};
