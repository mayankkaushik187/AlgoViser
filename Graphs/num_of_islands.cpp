#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
    {
        return;
    }
    //up-down-left-right-ne-se-nw-sw
    grid[i][j] = '0';
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i, j - 1, n, m);
    dfs(grid, i, j + 1, n, m);
    dfs(grid, i - 1, j + 1, n, m);
    dfs(grid, i - 1, j - 1, n, m);
    dfs(grid, i + 1, j - 1, n, m);
    dfs(grid, i + 1, j + 1, n, m);
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size(); //backtracking mien visited ki zarurat nahi hoti
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }

    return count;
}