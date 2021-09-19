#include <bits/stdc++.h>
using namespace std;
class Graph
{
    vector<int> *adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    int minCostBFS(int src, int dest)
    {
        queue<int> q;
        vector<int> dist(V, 0);
        vector<bool> visited(V, false);
        q.push(src);
        visited[src] = 1;
        dist[src] = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto e : adj[src])
            {
                if (!visited[e])
                {
                    q.push(e);
                    dist[e] = dist[src] + 1;
                    visited[e] = 1;
                }
            }
        }
        return dist[dest];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> board(n + 1, 0);

    for (auto x : snakes)
    {
        int s = x.first;
        int e = x.second;
        board[s] = e - s;
    }

    for (auto x : ladders)
    {
        int s = x.first;
        int e = x.second;
        board[s] = e - s;
    }
    Graph g(n + 1);
    for (int i = 1; i < n; i++)
    { //this is less than n because we dont want to make any move at the last cell.
        for (int dice = 1; dice <= 6; dice++)
        {
            int v = i + dice;
            v += board[v];
            if (v <= n)
            {
                g.addEdge(i, v);
            }
        }
    }
    return g.minCostBFS(1, n);
}
