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

void printKdown(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printKdown(root->left, k - 1);
    printKdown(root->right, k - 1);
}
int helper(BinaryTreeNode<int> *root, int target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == target)
    {
        printKdown(root, k);
        return 0;
    }

    int ld = helper(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printKdown(root->right, k - ld - 2);
        }

        return 1 + ld;
    }

    int rd = helper(root->right, target, k);

    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            printKdown(root->left, k - rd - 2);
        }

        return 1 + rd;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    // Write your code herez

    helper(root, node, k);
}