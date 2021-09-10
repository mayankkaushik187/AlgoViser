#include <iostream>
using namespace std;

int hasPath(int **edges, int v, int v1, int v2, int *visited)
{
    if (v1 == v2)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < v; i++)
    {
        if (edges[v1][i] == 1 && !visited[i])
        {
            visited[i] = 1;
            ans = hasPath(edges, v, i, v2, visited);

            if (ans)
            {
                return 1;
            }
        }
    }
    return ans;
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    int *visited = new int[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    if (hasPath(edges, v, v1, v2, visited))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}