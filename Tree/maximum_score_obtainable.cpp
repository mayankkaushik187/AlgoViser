long long findMaxScore(Node * root) {
    // Your code goes here
    if (!root) return 0;
    long long lans = findMaxScore(root -> left);
    long long rans = findMaxScore(root -> right);

    return max < long long > (root -> data, max < long long > (root -> data * lans, root -> data * rans));
}
