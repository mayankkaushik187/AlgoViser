//Leetcode 111
int minDepth(TreeNode * root) {
    if (!root) return 0;
    queue < TreeNode * > q;
    q.push(root);
    int i = 0;
    while (!q.empty()) {
        int k = q.size();
        i++;
        for (int j = 0; j < k; j++) {
            auto fr = q.front();
            q.pop();
            if (fr -> left) q.push(fr -> left);
            if (fr -> right) q.push(fr -> right);

            if (!fr -> left and!fr -> right) return i;
        }
    }

    return -1;
}
