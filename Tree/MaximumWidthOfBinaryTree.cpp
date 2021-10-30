#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;
        int maxWidth = 0;
        q.push({root, 0});
        while (!q.empty())
        {
            int k = q.size();
            int minm = q.front().second;
            int first, last;
            for (int i = 0; i < k; i++)
            {
                auto fr = q.front();
                q.pop();
                auto node = fr.first;
                auto id = fr.second;
                id = id - minm;
                if (i == 0)
                    first = id;
                if (i == k - 1)
                    last = id;
                if (node->left)
                {
                    q.push({node->left, id * 2 + 1});
                }
                if (node->right)
                {
                    q.push({node->right, id * 2 + 2});
                }
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};