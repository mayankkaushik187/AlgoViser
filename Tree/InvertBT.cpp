//Leetcode 226

//Recursive

TreeNode * invertTree(TreeNode * root) {
    if (root) {
        invertTree(root -> left);
        invertTree(root -> right);
        swap(root -> left, root -> right);
    }

    return root;
}
//Iterative
TreeNode * invertTree(TreeNode * root) {
    if (root == NULL) return root;

    queue < TreeNode * > q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node) {
            q.push(node -> left);
            q.push(node -> right);
            swap(node -> left, node -> right);
        }
    }

    return root;
}
  
