#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random;
};
Node *copyLeftRightNode(Node *treeNode, unordered_map<Node *, Node *> &mymap)
{
    if (treeNode == NULL)
        return NULL;
    Node *cloneNode = new Node(treeNode->data);
    mymap[treeNode] = cloneNode;
    cloneNode->left = copyLeftRightNode(treeNode->left, mymap);
    cloneNode->right = copyLeftRightNode(treeNode->right, mymap);
    return cloneNode;
}

// This function copies random node by using the hashmap built by
// copyLeftRightNode()
void copyRandom(Node *treeNode, Node *cloneNode, unordered_map<Node *, Node *> &mymap)
{
    if (cloneNode == NULL)
        return;
    cloneNode->random = mymap[treeNode->random];
    copyRandom(treeNode->left, cloneNode->left, mymap);
    copyRandom(treeNode->right, cloneNode->right, mymap);
}

// This function makes the clone of given tree. It mainly uses
// copyLeftRightNode() and copyRandom()
Node *cloneTree(Node *tree)
{
    if (tree == NULL)
        return NULL;
    unordered_map<Node *, Node *> mymap;
    Node *newTree = copyLeftRightNode(tree, mymap);
    copyRandom(tree, newTree, mymap);
    return newTree;
}