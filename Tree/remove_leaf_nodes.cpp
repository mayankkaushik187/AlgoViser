#include <bits/stdc++.h>
using namespace std;

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

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    if (!root->left && !root->right)
    {
        delete root;
        return NULL;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}