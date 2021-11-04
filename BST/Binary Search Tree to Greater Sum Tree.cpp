//Leetcode 1038
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
class Solution {
public:
    void helper(TreeNode* root,int &prevSum){
        if(!root)return;
        helper(root->right,prevSum);
        root->val += prevSum;
        prevSum = root->val;
        helper(root->left,prevSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)return root;
        int prevSum = 0;
        helper(root,prevSum);
        return root;
    }
};
