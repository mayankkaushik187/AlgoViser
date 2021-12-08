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
    int val = 0;
    private:
    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto lans = helper(root->left);
        auto rans = helper(root->right);
        
        pair<int,int> ans;
        ans.first = root->val + lans.first + rans.first;
        ans.second = abs(lans.first - rans.first);
        val += ans.second;
        return ans;
    }
    public:
    int findTilt(TreeNode* root) {
        helper(root);
        return val;
    }
};
