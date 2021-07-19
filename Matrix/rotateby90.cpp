#include <bits/stdc++.h>
using namespace std;

void rotateAnticlock(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            swap(v[low][i], v[high][i]);
            low++;
            high--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotateAnticlock(v);
    return 0;
}