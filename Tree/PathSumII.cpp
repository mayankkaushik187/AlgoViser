//leetcode 113
vector < vector < int >> res;
void helper(TreeNode * root, int sum, vector < int > v) {
    if (!root) {
        return;
    }
    if (root -> val == sum and!root -> left and!root -> right) {
        v.push_back(root -> val);
        res.push_back(v);
        return;
    }
    v.push_back(root -> val);
    helper(root -> left, sum - root -> val, v);
    helper(root -> right, sum - root -> val, v);
}
vector < vector < int >> pathSum(TreeNode * root, int targetSum) {
    if (!root) return {};
    vector < int > v;
    helper(root, targetSum, v);
    return res;
}
