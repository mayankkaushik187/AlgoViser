#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size(), m = grid[0].size();
    int timeReq = 0;
    int totOranges = 0, count = 0; //count indicates oranges that got rotten over the time
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                totOranges++;
            }
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        int k = q.size();
        count += k;
        while (k--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
        if (!q.empty())
        {
            timeReq++;
        }
    }

    return totOranges == count ? timeReq : -1;
}