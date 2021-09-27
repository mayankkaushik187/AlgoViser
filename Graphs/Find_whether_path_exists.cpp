#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<bool> &vis)
{
    if (i < 0 || j < 0 || j >= m || i >= n || grid[i][j] == 0)
    {
        return;
    }
    vis[grid[i][j]] = true;
    grid[i][j] = 0;
    dfs(grid, i + 1, j, n, m, vis);
    dfs(grid, i - 1, j, n, m, vis);
    dfs(grid, i, j + 1, n, m, vis);
    dfs(grid, i, j - 1, n, m, vis);
}
bool is_Possible(vector<vector<int>> &grid)
{
    //code here
    vector<bool> vis(5, 0);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, grid.size(), grid[i].size(), vis);
            }
        }
    }

    if (vis[2])
    {
        return true;
    }

    return false;
}