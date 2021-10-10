//Leetcode -- 116
//O(n) - space  O(N) time
Node * connect(Node * root) {
    if (!root) return NULL;
    queue < Node * > q;
    q.push(root);
    while (!q.empty()) {
        int k = q.size();
        vector < Node * > temp;
        for (int i = 0; i < k; i++) {
            auto f = q.front();
            q.pop();
            temp.push_back(f);
            if (f -> left) q.push(f -> left);
            if (f -> right) q.push(f -> right);

        }
        for (int i = 0; i < temp.size() - 1; i++) {
            temp[i] -> next = temp[i + 1];
        }
        temp[temp.size() - 1] -> next = NULL;
    }

    return root;

}
//O(1) space explicit O(n) time 
void helper(Node * node1, Node * node2) {
    if (node1 == NULL) return;
    node1 -> next = node2;
    helper(node1 -> left, node1 -> right);
    helper(node2 -> left, node2 -> right);
    helper(node1 -> right, node2 -> left);
}
Node * connect(Node * root) {
    if (root == NULL) return NULL;

    helper(root -> left, root -> right);
    return root;
}
