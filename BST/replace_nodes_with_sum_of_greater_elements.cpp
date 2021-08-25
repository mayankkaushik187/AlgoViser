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

static int sum = 0; // bad practice  should not use global vars and should be passed as an argument.
//the whole idea is traverse in reverse in order in the bst and update the sum with the value of the root->data.
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (!root)
        return;

    replaceWithLargerNodesSum(root->right);
    //data retain karo in a temp var and then chnge the root data and then chnge the sum by adding temp into it.
    int temp = root->data;
    root->data = sum + root->data;
    sum += temp;

    replaceWithLargerNodesSum(root->left);
}