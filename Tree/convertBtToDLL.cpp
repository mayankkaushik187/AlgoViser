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

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

Node *BTToDLL(Node *root) // This solution is based on the inorder traversal technique
{
    if (root == NULL)
        return NULL;
    static Node *prev = NULL;
    Node *head = BTToDLL(root->left);
    if (prev == NULL) // Will only happen for the first node of the DLL
        head = root;
    else
    {
        root->left = prev; //for every node whose prev is not null
        prev->right = root;
    }
    prev = root; //change the prev as the current root so that we can link its right or next to the next node;
    BTToDLL(root->right);
    return head;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    Node *head = BTToDLL(root);
    printlist(head);
}