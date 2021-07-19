#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v)
{
    int row = v.size();
    int colm = v[0].size();

    if (row == 1)
    {
        for (int i = 0; i < colm; i++)
        {
            cout << v[0][i] << " ";
        }
    }
    else if (colm == 1)
    {
        for (int i = 0; i < row; i++)
        {
            cout << v[i][0] << " ";
        }
    }
    else
    {
        for (int i = 0; i < colm; i++)
        {
            cout << v[0][i] << " ";
        }
        for (int i = 1; i < row; i++)
        {
            cout << v[i][colm - 1] << " ";
        }
        for (int i = colm - 2; i >= 0; i--)
        {
            cout << v[row - 1][i] << " ";
        }
        for (int i = row - 2; i >= 1; i--)
        {
            cout << v[i][0] << " ";
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(v);
    return 0;
}