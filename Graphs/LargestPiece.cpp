#include <bits/stdc++.h>
using namespace std;
/*
It's Gary's birthday today and he has ordered his favourite
 square cake consisting of '0's and '1's . But Gary wants the
  biggest piece of '1's and no '0's . A piece of cake is defined
   as a part which consist of only '1's, and all '1's share an edge 
   with each other on the cake. Given the size of cake N and the cake,
    can you find the count of '1's in the biggest piece of '1's for Gary ?
*/
void dfs(vector<vector<int>> &cake, int n, int i, int j, int &k)
{
    k++;
    cake[i][j] = 0; //so that we dont consider this piece again

    if (i + 1 < n && cake[i + 1][j])
    {
        dfs(cake, n, i + 1, j, k);
    }
    if (j + 1 < n && cake[i][j + 1])
    {
        dfs(cake, n, i, j + 1, k);
    }
    if (i - 1 >= 0 && cake[i - 1][j])
    {
        dfs(cake, n, i - 1, j, k);
    }
    if (j - 1 >= 0 && cake[i][j - 1])
    {
        dfs(cake, n, i, j - 1, k);
    }
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1)
            {
                int k1 = 0;
                dfs(cake, n, i, j, k1);
                ans = max(ans, k1);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}