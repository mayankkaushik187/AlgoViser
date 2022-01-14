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
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(NULL);
        }
        for(int rootData = start ; rootData <= end ; rootData++){
            auto leftSubtree = buildTree(start, rootData - 1);
            auto rightSubtree = buildTree(rootData + 1, end);
            
            for(auto lnode : leftSubtree){
                for(auto rnode : rightSubtree){
                    TreeNode* root_node = new TreeNode(rootData);
                    root_node -> left = lnode;
                    root_node -> right = rnode;
                    ans.push_back(root_node);
                }
            }
        }
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};
