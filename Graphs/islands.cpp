#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;

    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSRec(adj, u, visited);
    }
}

int DFS(vector<int> adj[], int V, int s) //works for disconnected graphs and counts the no of connected components
{
    int count = 0;
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            count++; //add this to count connected components
            DFSRec(adj, i, visited);
        }
    }

    return count;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];

    for (int i = 0; i < e; i++)
    {
        int s, f;
        cin >> s >> f;
        adj[s].push_back(f);
        adj[f].push_back(s);
    }

    cout << DFS(adj, v, 0) << endl;
}