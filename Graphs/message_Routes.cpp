#include <bits/stdc++.h>
using namespace std;
//to find if there is a path from source to destination if it exists the return the minimum no of vertices along that path
int bfs(int src, int dest, vector<vector<int>> edges, int n)
{
    vector<int> dist(n + 1, -1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto x : edges[f])
        {
            if (!visited[x])
            {
                q.push(x);
                dist[x] = 1 + dist[f];
                visited[x] = true;
            }
        }
    }

    return dist[dest];
}
int messageRoute(int n, vector<vector<int>> edges)
{
    vector<vector<int>> res(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        res[v].push_back(u);
        res[u].push_back(v);
    }
    return bfs(1, n, res, n);
}