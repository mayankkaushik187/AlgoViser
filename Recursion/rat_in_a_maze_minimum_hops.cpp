#include <bits/stdc++.h>
using namespace std;

void print(vector<int> res[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(vector<int> maze[], int i, int j, int N)
{
    return i < N && j < N && maze[i][j] != 0;
}

bool solRec(int i, int j, vector<int> maze[], vector<int> sol[], int N)
{
    if (i == N - 1 && j == N - 1)
    {
        sol[i][j] = 1;
        return true;
    }

    if (isSafe(maze, i, j, N) == true)
    {
        int jumps = maze[i][j];
        sol[i][j] = 1;

        for (int k = 1; k <= jumps; k++)
        {
            if (solRec(i, j + k, maze, sol, N) == true)
            {
                return true;
            }
            if (solRec(i + k, j, maze, sol, N) == true)
            {
                return true;
            }
        }

        sol[i][j] = 0;
    }

    return false;
}

void solve(int N, vector<int> maze[])
{
    vector<int> sol[N];
    for (int i = 0; i < N; i++)
    {
        sol[i].assign(N, 0);
    }

    if (solRec(0, 0, maze, sol, N) == false)
    {
        cout << "-1\n";
    }
    else
    {
        print(sol, N);
    }
}