#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
    }
};

void convert(Node *head, TreeNode *&root)
{
    // Your code here
    vector<TreeNode *> v;
    while (head != NULL)
    { //fill the whole vector
        TreeNode *temp = new TreeNode(head->data);
        v.push_back(temp);
        head = head->next;
    }

    int n = v.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (2 * i + 1 < n)
        {
            v[i]->left = v[2 * i + 1];
        }
        if (2 * i + 2 < n)
        {
            v[i]->right = v[2 * i + 2];
        }
    }
    root = v[0];
}