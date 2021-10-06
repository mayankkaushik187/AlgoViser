struct TreeNode {
    * int val;
    * TreeNode * left;
    * TreeNode * right;
    * TreeNode(): val(0), left(nullptr), right(nullptr) {}
        * TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
        * TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right) {}
        *
};

TreeNode * conversion(vector < int > & nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode * node = new TreeNode(nums[mid]);
    node -> left = conversion(nums, start, mid - 1);
    node -> right = conversion(nums, mid + 1, end);

    return node;
}
TreeNode * sortedArrayToBST(vector < int > & nums) {
    TreeNode * root = conversion(nums, 0, nums.size() - 1);
    return root;
}
