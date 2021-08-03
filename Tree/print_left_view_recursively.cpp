#include <bits/stdc++.h>
using namespace std;
//Time Complexity = O(n);
//Aux Space = O(h) h->height of the tree;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int maxLevel = 0;
void helper(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (maxLevel < level)
    {
        cout << root->key << " ";
        maxLevel = level;
    }
    helper(root->left, level + 1);
    helper(root->right, level + 1);
}
void printLevel(Node *root)
{
    helper(root, 1);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printLevel(root);
}