//Leetcode 257
vector < string > binaryTreePaths(TreeNode * root) {
    if (!root) return {};
    vector < string > res;

    queue < TreeNode * > q;
    queue < string > qstr;
    qstr.push("");
    q.push(root);
    while (!q.empty()) {
        auto fr = q.front();
        auto curr_path = qstr.front();
        qstr.pop();
        q.pop();
        if (!fr -> left and!fr -> right) res.push_back(curr_path + to_string(fr -> val));
        if (fr -> left) {
            q.push(fr -> left);
            qstr.push(curr_path + to_string(fr -> val) + "->");
        }
        if (fr -> right) {
            q.push(fr -> right);
            qstr.push(curr_path + to_string(fr -> val) + "->");
        }
    }
    return res;
}
