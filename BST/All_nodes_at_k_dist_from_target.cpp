//Leetcode 863

class Solution {
private:
    void mark_parent(unordered_map<TreeNode* , TreeNode*> &parent_map,TreeNode* root){
        queue<TreeNode*> Q;
        Q.push(root);
        parent_map[root] = NULL;
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto curr = Q.front();
                Q.pop();
                if(curr -> left){
                    parent_map[curr->left] = curr;
                    Q.push(curr -> left);
                }
                if(curr -> right){
                    parent_map[curr->right] = curr;
                    Q.push(curr -> right);
                }
            }
        }
    }
    void runBFS(unordered_map<TreeNode* , bool>&visited,TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent_map,TreeNode* target,int k,queue<TreeNode* > &Q){
        Q.push(target);
        visited[target] = true;
        int level = 0;
        while(!Q.empty()){
            int size = Q.size();
            if(level == k)break;
            while(size--){
                auto curr = Q.front();
                Q.pop();
                if(curr -> left and !visited[curr -> left]){
                    Q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                if(curr -> right and !visited[curr -> right]){
                    Q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                if(parent_map[curr] and !visited[parent_map[curr]]){
                    Q.push(parent_map[curr]);
                    visited[parent_map[curr]] = true;
                }
            }
            level++;
        }
    }
    void fillVector(queue<TreeNode*> &Q,vector<int>&res){
        while(!Q.empty()){
            auto front = Q.front();
            Q.pop();
            res.push_back(front -> val);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode* > parent_map;
        mark_parent(parent_map,root);
        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> Q;
        runBFS(visited,root,parent_map,target,k,Q);
        vector<int> res;
        fillVector(Q,res);
        return res;
    }
};
