/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        helperSerialize(root,res);
        return res;
    }
    void helperSerialize(TreeNode* root,string &s){
        if(!root)return;
        s += (to_string(root->val) + ',');
        helperSerialize(root->left,s);
        helperSerialize(root->right,s);
    }
    TreeNode* helperDes(string &s,int min,int max){
        if(s.size() == 0)return NULL;
        int pos = 0;
        pos = s.find(',');
        int val = stoi(s.substr(0,pos));
        if(val < min or val > max)return NULL;
        s = s.substr(pos + 1);
        TreeNode* root = new TreeNode(val);
        root -> left = helperDes(s,min,root -> val);
        root -> right = helperDes(s,root -> val, max);
        
        return root;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;
        return helperDes(data,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
