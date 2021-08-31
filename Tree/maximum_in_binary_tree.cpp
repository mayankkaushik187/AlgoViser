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
//max in a BT
int maxi(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->key, max(maxi(root->left), maxi(root->right)));
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

    cout << maxi(root);
}