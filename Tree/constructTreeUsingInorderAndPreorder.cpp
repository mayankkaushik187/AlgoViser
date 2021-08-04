#include <bits/stdc++.h>
using namespace std;
//TC - O(n^2) but can be reduced to O(N) using hashing for lookups for the root->key in the inorder array.
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int preIndex = 0;
Node *cTree(int in[], int pre[], int is, int ie)
{
    if (is > ie)
    {
        return NULL;
    }
    int inIndex = 0;
    Node *root = new Node(pre[preIndex++]);
    for (int i = is; i <= ie; i++)
    {
        if (root->key == in[i])
        {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}

int main()
{

    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);
    Node *root = cTree(in, pre, 0, n - 1);
    inorder(root);
}