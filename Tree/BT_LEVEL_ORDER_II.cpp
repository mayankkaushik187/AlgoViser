class Solution {
public:
  //leetcode 
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)return;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            vector<int> temp;
            for (int i = 0 ; i < k ; i++) {
                auto fr = q.front();
                q.pop();
                temp.push_back(fr->val);
                if (fr->left)q.push(fr->left);
                if (fr->right)q.push(fr->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());//this is nothing as it take o(n) for reversing n element but in our res vector we only have height of binary elements o(height) 
        return res;
    }
};
