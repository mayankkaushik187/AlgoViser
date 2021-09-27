#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'O')
    {
        return;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    grid[i][j] = 'O';
    for (int l = 0; l < 4; l++)
    {
        dfs(grid, i + dx[l], j + dy[l], n, m);
    }
}
int xShape(vector<vector<char>> &grid)
{
    // Code here
    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            int n = grid.size();
            int m = grid[i].size();
            if (grid[i][j] == 'X')
            {
                count++;
                dfs(grid, i, j, n, m);
            }
        }
    }

    return count;
}