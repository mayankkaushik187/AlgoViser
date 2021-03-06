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

void BToCDLL(Node *root, Node **head)
{
    static Node *prev = NULL;
    if (!root)
        return;
    BToCDLL(root->left, head);
    if (!(*head))
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BToCDLL(root->right, head);
}

Node *bTreeToCList(Node *root)
{
    Node *head = NULL;
    BToCDLL(root, &head);
    Node *last, *p = head;
    while (p != NULL)
    {
        last = p;
        p = p->right;
    }
    last->right = head;
    head->left = last;
    return head;
}