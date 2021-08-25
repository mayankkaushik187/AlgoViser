
class isBSTHeight
{
public:
    int minm;
    int maxm;
    bool isBST;
    int height;
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
#include <bits/stdc++.h>
isBSTHeight helper(BinaryTreeNode<int> *root)
{
    //base case
    if (!root)
    {
        isBSTHeight ans;
        ans.minm = INT_MAX;
        ans.maxm = INT_MIN;
        ans.isBST = true;
        ans.height = 0;

        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        isBSTHeight ans;
        ans.minm = root->data;
        ans.maxm = root->data;
        ans.isBST = true;
        ans.height = 1;

        return ans;
    }

    isBSTHeight lAns = helper(root->left);
    isBSTHeight rAns = helper(root->right);

    isBSTHeight ans;

    if (lAns.isBST && rAns.isBST && root->data < rAns.minm && root->data > lAns.maxm)
    {
        ans.minm = min(root->data, min(lAns.minm, rAns.minm));
        ans.maxm = max(root->data, max(lAns.maxm, lAns.minm));
        ans.isBST = true;
        ans.height = 1 + max(lAns.height, rAns.height);
    }
    else
    {
        ans.minm = min(root->data, min(lAns.minm, rAns.minm));
        ans.maxm = max(root->data, max(lAns.maxm, lAns.minm));
        ans.isBST = false;
        ans.height = max(lAns.height, rAns.height);
    }

    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    isBSTHeight ans = helper(root);

    return ans.height;
}