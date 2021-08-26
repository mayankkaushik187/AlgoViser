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

Node *bToDLL(Node *root)
{
    static Node *prev = nullptr;
    Node *head = nullptr;
    if (root)
    {
        head = bToDLL(root->left);
        if (prev == nullptr)
        {
            head = root;
            prev = root;
        }
        else
        {
            prev->right = root;
            root->left = prev;
            prev = root;
        }
        bToDLL(root->right);
    }
    return head;
}