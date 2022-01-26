class Solution {
public:
    vector<int> ans;
    void merge(vector<int>&a,vector<int>&b){ 
        int i = 0,j = 0;
        int n = a.size();
        int m = b.size();
        while(i < n and j < m){
            if(a[i] < b[j]){
                ans.push_back(a[i++]);
            }else if(a[i] >= b[j]){
                ans.push_back(b[j++]);
            }
        }
        while(i < n){
            ans.push_back(a[i++]);
        }
        while(j < m){
            ans.push_back(b[j++]);
        }
    }
    void helper(TreeNode* root,vector<int> &res1){
        if(!root)return;
        helper(root->left,res1);
        res1.push_back(root->val);
        helper(root->right,res1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2;
        helper(root1,res1);
        helper(root2,res2);
        merge(res1,res2);
        return ans;
    }
};
