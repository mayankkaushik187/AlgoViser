//leetcode 117
Node * connect(Node * root) {
    if (!root) return NULL;
    queue < Node * > q;
    q.push(root);
    while (!q.empty()) {
        int k = q.size();
        for (int i = 0; i < k; i++) {
            auto fr = q.front();
            q.pop();
            if (i == k - 1) {
                fr -> next = NULL;
            } else {
                auto nxt = q.front();
                fr -> next = nxt;
            }
            if (fr -> left) {
                q.push(fr -> left);
            }
            if (fr -> right) {
                q.push(fr -> right);
            }
        }
    }
    return root;
}
