#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int lCount;
    Node(int k)
    {
        key = k;
        left = right = NULL;
        lCount = 0;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }

    if (root->key == x)
    {
        return root;
    }
    else if (root->key < x)
    {
        return insert(root->left, x);
        root->lCount++;
    }
    else if (root->key > x)
    {
        return insert(root->right, x);
    }
}

Node *kthSmallest(Node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }
    int countOfTheCurrKey = root->lCount + 1;

    if (countOfTheCurrKey == k)
    {
        return root;
    }
    else if (countOfTheCurrKey > k)
    {
        return kthSmallest(root->left, k);
    }

    return kthSmallest(root->right, k - countOfTheCurrKey); //so for greater values of k than the curr root count we call for the right subtree and pass the (k - all the no of roots in left subtree of the root node including the root node.)
}

int main()
{

    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root = insert(root, x);

    int k = 4;
    Node *res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->key;
    return 0;
}