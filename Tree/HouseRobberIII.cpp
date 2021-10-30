//Leetcode 337
pair < int, int > helper(TreeNode * root) {
    if (!root) return {
        0,
        0
    };
    auto lans = helper(root -> left);
    auto rans = helper(root -> right);

    pair < int, int > res;
    int robIt = root -> val + lans.second + rans.second;
    int skipIt = max(lans.first, lans.second) + max(rans.first, rans.second);

    res = make_pair(robIt, skipIt);
    return res;
}
int rob(TreeNode * root) {
    if (!root) return 0;
    auto ans = helper(root);
    return max(ans.first, ans.second);
}
