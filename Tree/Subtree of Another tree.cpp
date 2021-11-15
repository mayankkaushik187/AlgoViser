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
    bool isSame(TreeNode* r,TreeNode* s){
        if(!r and !s)return true;
        if(!r or !s)return false;
        if(r->val != s->val)return false;
        
        return isSame(r->left,s->left) and isSame(r->right,s->right);
    }
    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!r)return false;
        if(!s)return true;
        if(isSame(r,s))return true;
        
        return isSubtree(r->left,s) or isSubtree(r->right,s);
    }
};
