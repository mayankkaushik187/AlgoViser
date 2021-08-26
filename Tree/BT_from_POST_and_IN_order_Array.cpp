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

Node *construct(int in[], int po[], int inS, int inE, int poS, int poE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = po[poE];
    int rootIndex = 0;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int l_inS = inS;
    int l_inE = rootIndex - 1;
    int l_poS = poS;
    int l_poE = l_inE - l_inS + l_poS;

    int r_inS = rootIndex + 1;
    int r_inE = inE;
    int r_poS = l_poE + 1;
    int r_poE = poE - 1;

    Node *root = new Node(rootData);
    root->left = construct(in, po, l_inS, l_inE, l_poS, l_poE);
    root->right = construct(in, po, r_inS, r_inE, r_poS, r_poE);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    Node *root = construct(in, post, 0, n - 1, 0, n - 1);

    return root;
}