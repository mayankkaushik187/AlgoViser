#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

void help(Node *root, int &minm, int &maxm, int hd)
{
    if (!root)
    {
        return;
    }
    help(root->left, minm, maxm, hd - 1);

    maxm = max(maxm, curr);
    minm = min(minm, curr);

    help(root->right, minm, maxm, hd + 1);
}
int verticalWidth(Node *root)
{
    // Code here
    if (!root)
    {
        return 0;
    }
    int minm = INT_MAX;
    int maxm = INT_MIN;

    help(root, minm, maxm, 0);
    return abs(minm) + maxm + 1;
}