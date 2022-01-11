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
    int res = 0;
    void helper(TreeNode* root,string s){
        if(!root)return;
        s += to_string(root->val);
         if(!root->left and !root->right){
             int x = s.size() - 1;
             int ans = 0;
             for(int i = 0 ; i < s.size() ; i++){
                 ans += pow(2,x)*(s[i] - '0');
                 x--;
             }
             // cout<<ans<<endl;
             res += ans;
             return;
         }        
        helper(root->left,s);
        helper(root->right,s);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        helper(root,s);
        
        return res;
    }
};
