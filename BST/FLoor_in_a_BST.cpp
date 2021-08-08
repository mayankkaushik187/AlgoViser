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

void Floor(Node *root, int x)
{
    Node *potNode = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->key > x)
        {
            curr = curr->left;
        }
        else if (curr->key < x)
        {
            potNode = curr;
            curr = curr->right;
        }
        else
        {
            cout << curr->key << " is the Floor of this BST";
            return;
        }
    }
    cout << potNode->key << " is the Floor of this BST";
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
    Floor(root, x);
    return 0;
}