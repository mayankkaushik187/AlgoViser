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

void bottomView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int hd = q.front().second;

        mp[hd] = curr->key;
        q.pop();

        if (curr->left)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, hd + 1});
        }
    }

    for (auto i : mp)
    {
        cout << i.second << " ";
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    bottomView(root);

    return 0;
}