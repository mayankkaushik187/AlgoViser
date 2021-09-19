#include <bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> &edges)
{
    vector<int> degree(n + 1);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (auto &e : edges)
    {
        ++degree[e[0]];
        ++degree[e[1]];
        adj[e[0]][e[1]] = 1;
        adj[e[1]][e[0]] = 1;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] < 2)
            continue;
        for (int j = i + 1; j <= n; ++j)
        {
            if (degree[j] < 2)
                continue;
            if (!adj[i][j])
                continue;
            for (int k = j + 1; k <= n; ++k)
            {
                if (degree[k] < 2)
                    continue;
                if (adj[i][j] && adj[j][k] && adj[k][i])
                {
                    ans = min(ans, degree[i] - 2 + degree[j] - 2 + degree[k] - 2);
                }
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
