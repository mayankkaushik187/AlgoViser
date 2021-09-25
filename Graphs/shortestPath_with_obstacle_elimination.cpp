#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid, int k)
{
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
    queue<vector<int>> q;
    if (k >= grid.size() + grid[0].size() - 2)
    {
        return grid.size() + grid[0].size() - 2;
    }
    q.push({0, 0, 0, k}); /*the vector values are the coordiantes the no of steps till now and skips allowed*/

    while (!q.empty())
    {
        auto val = q.front();
        int i = val[0], j = val[1];
        int steps = val[2], skips = val[3];

        q.pop();

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            continue;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return steps;
        }
        if (grid[i][j] == 1)
        {
            if (skips > 0)
            {
                skips--;
            }
            else
            {
                continue;
            }
        }
        if (vis[i][j] != -1 && vis[i][j] >= skips)
        { //agar current skipping capacity se zyada hai no of obstacles toh continue karo
            continue;
        }
        vis[i][j] = skips;
        q.push({i, j + 1, steps + 1, skips});
        q.push({i + 1, j, steps + 1, skips});
        q.push({i, j - 1, steps + 1, skips});
        q.push({i - 1, j, steps + 1, skips});
    }

    return -1;
}
int shortestPath(vector<vector<int>> &grid, int k)
{
    return bfs(grid, k);
}