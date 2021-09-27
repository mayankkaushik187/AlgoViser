#include <bits/stdc++.h>
using namespace std;

int bfs_helper(vector<int> adj[], int V, int target, vector<bool> &visited)
{
    queue<int> q;
    q.push(0); // push the source node
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        // process level by level
        while (size--)
        {
            int front = q.front();
            q.pop();
            // visit the neighbour nodes
            if (front == target)
                return level;
            for (int &nbr : adj[front])
            {
                // if the neighbor is not visited: add it in the queue
                if (!visited[nbr])
                {
                    q.push(nbr);
                    // mark the neighbor as visited
                    visited[nbr] = true;
                }
            }
        }
        // increase the level
        level++;
    }
    // the node is not found
    return -1;
}
int nodeLevel(int V, vector<int> adj[], int X)
{
    // code here
    vector<bool> visited(V, 0);
    vector<int> level(V + 1, -1);
    return bfs_helper(adj, V, X, visited);
}