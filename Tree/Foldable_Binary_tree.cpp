#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool isMirror(Node *root1, Node *root2)
{
    // base cases: both are empty
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    // recursive calls
    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}