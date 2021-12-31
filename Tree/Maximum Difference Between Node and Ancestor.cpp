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
    int ans;
    void helper(TreeNode* root,int minm,int maxm){
        if(!root)return;
        
        minm = min(minm,root->val);
        maxm = max(maxm,root->val);
        ans = max(abs(minm - maxm) , ans);
        helper(root->left,minm,maxm);
        helper(root->right,minm,maxm);

        
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};
