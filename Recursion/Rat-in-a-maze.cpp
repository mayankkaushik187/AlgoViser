#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int> > &m, vector<vector<int> > &vis, int n, vector<string> &res, string psf, int i, int j)
{
    if (i >= 0 and j >= 0 and i < n and j < n and m[i][j] == 1 and vis[i][j] == 0)
    {
        if (i == n - 1 and j == n - 1)
        {
            res.push_back(psf);
            return;
        }
        vis[i][j] = 1;
        helper(m, vis, n, res, psf + 'D', i + 1, j);
        helper(m, vis, n, res, psf + 'R', i, j + 1);
        helper(m, vis, n, res, psf + 'U', i - 1, j);
        helper(m, vis, n, res, psf + 'L', i, j - 1);
        vis[i][j] = 0;
    }
}
vector<string> findPath(vector<vector<int> > &m, int n)
{
    // Your code goes here
    vector<string> res;
    vector<vector<int> > vis(n, vector<int>(n, 0));
    helper(m, vis, n, res, "", 0, 0);
    if (res.size() == 0)
        return {"-1"};
    sort(res.begin(), res.end());
    return res;
}
