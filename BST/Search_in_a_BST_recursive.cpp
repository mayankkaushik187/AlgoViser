#include <bits/stdc++.h>
using namespace std;

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

bool search(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key < x)
    {
        return search(root->right, x);
    }
    else if (root->key > x)
    {
        return search(root->left, x);
    }
    else
    {
        return true;
    }
}

int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int x = 16;

    if (search(root, x))
        cout << "Found";
    else
        cout << "Not Found";
}