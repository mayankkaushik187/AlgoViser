#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX));
    queue<pair<int, int>> q;
    vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
    dist[KnightPos[0]][KnightPos[1]] = 0;
    q.push({KnightPos[0], KnightPos[1]});
    vis[KnightPos[0]][KnightPos[1]] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == TargetPos[0] && y == TargetPos[1])
            return dist[x][y];
        q.pop();
        int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx == TargetPos[0] && ny == TargetPos[1])
            {
                return dist[x][y] + 1;
            }
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || vis[nx][ny])
            {
                continue;
            }
            q.push({nx, ny});
            vis[nx][ny] = 1;
            dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
        }
    }
    return dist[TargetPos[0]][TargetPos[1]];
}