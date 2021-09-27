#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, INT_MAX)); //intmax beacuse we are using bfs which will always give us minimum distance
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto curr = q.front();
        int currX = curr.first;
        int currY = curr.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = currX + dx[i];
            int y = currY + dy[i];

            if (x >= 0 and y >= 0 and x < n and y < m)
            {
                if (res[x][y] > res[curr.first][curr.second] + 1)
                {
                    res[x][y] = res[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    return res;
}