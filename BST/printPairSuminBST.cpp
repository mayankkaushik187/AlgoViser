#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printHelp(vector<int> &arr, int sum)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }
    }
}
void fillVect(BinaryTreeNode<int> *root, vector<int> &arr)
{
    if (!root)
        return;

    fillVect(root->left, arr);
    arr.push_back(root->data);
    fillVect(root->right, arr);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    // Write your code here
    if (!root)
    {
        return;
    }

    vector<int> arr;
    fillVect(root, arr);
    printHelp(arr, s);
}