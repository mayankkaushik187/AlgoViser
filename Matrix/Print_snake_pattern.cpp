#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
        }
        else
        {
            for (int j = v[i].size() - 1; j >= 0; j--)
            {
                cout << v[i][j] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(v);
    return 0;
}