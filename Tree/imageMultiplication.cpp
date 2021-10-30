#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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

long long helper(Node *root1, Node *root2)
{
    if (!root1 or !root2)
        return 0;

    return ((root1->data * root2->data) % mod + helper(root1->left, root2->right) + helper(root1->right, root2->left)) % mod;
}

long long imgMultiply(Node *root)
{
    // code here
    long long ans = ((root->data * root->data) % mod + helper(root->left, root->right)) % mod;

    return ans;
}