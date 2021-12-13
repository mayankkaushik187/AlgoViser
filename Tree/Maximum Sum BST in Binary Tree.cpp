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
    int val;
    struct isBST{
        bool isBST;
        int sum;
        int maxm;
        int minm;
    };
    isBST helper(TreeNode* root){
        if(!root){
            isBST ans;
            ans.sum = 0;
            ans.maxm = INT_MIN;
            ans.minm = INT_MAX;
            ans.isBST = true;
            val = max(val,ans.sum);
            return ans;
        }
        
        auto lans = helper(root->left);
        auto rans = helper(root->right);
        
        if(root->left == NULL and root->right == NULL){
            isBST ans;
            ans.minm = root->val;
            ans.maxm = root->val;
            ans.isBST = true;
            ans.sum = root->val;
            
            val = max(val,ans.sum);
            return ans;
        }
        
        isBST ans;
        
        
        if(lans.maxm < root->val and rans.minm > root->val and rans.isBST and lans.isBST){
            ans.sum = root->val + lans.sum + rans.sum;
            ans.isBST = true;
            ans.minm = min(root->val,min(lans.minm,rans.minm));
            ans.maxm = max(root->val,max(rans.maxm,lans.maxm));
        }else{
            ans.sum = max(lans.sum,rans.sum);
            ans.minm = min(lans.minm,rans.minm);
            ans.maxm = max(rans.maxm,lans.maxm);
            ans.isBST = false;
            
        }
        val = max(val , ans.sum);
        
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        val = INT_MIN;
        isBST ans = helper(root);
        return val;
    }
};
