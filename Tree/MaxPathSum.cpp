#include <bits/stdc++.h>
using namespace std;
//IMP
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

int help(Node *root, int &maxi)
{
    if (!root)
        return 0;

    int lans = max(0, help(root->left, maxi));
    int rans = max(0, help(root->right, maxi));

    maxi = max(maxi, root->data + lans + rans);

    return root->data + max(lans, rans);
}

int findMaxSum(Node *root)
{
    // Your code goes here
    if (!root)
        return 0;
    int maxi = INT_MIN;
    help(root, maxi);

    return maxi;
}