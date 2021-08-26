#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left, *right;
};
void storeInorder(Node *root, char arr[], int &i)
{
    if (!root)
    {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->data;
    storeInorder(root->right, arr, i);
}

// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node *root, char arr[], int &i)
{
    if (!root)
    {
        arr[i++] = '$';
        return;
    }

    arr[i++] = root->data;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node *T, Node *S)
{
    /* base cases */
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;

    // Store Inorder traversals of T and S in inT[0..m-1]
    // and inS[0..n-1] respectively
    int m = 0;
    int n = 0;
    char inT[1000], inS[1000];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0';
    inS[n] = '\0';

    // If inS[] is not a substring of inT[], return false
    if (strstr(inT, inS) == NULL)
        return false;

    // Store Preorder traversals of T and S in preT[0..m-1]
    // and preS[0..n-1] respectively
    int x = 0;
    int y = 0;
    char preT[1000], preS[1000];
    storePreOrder(T, preT, x);
    storePreOrder(S, preS, y);
    preT[x] = '\0';
    preS[y] = '\0';

    // If preS[] is not a substring of preT[], return false
    // Else return true
    if (strstr(preT, preS) != NULL)
        return true;

    return false;
}