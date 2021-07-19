#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v)
{
    int row = v.size();
    int colm = v[0].size();
    int top = 0;
    int bottom = row - 1;
    int right = colm - 1;
    int left = 0;

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
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                cout << v[top][i] << " ";
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                cout << v[i][right] << " ";
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    cout << v[bottom][i] << " ";
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    cout << v[i][left] << " ";
                }
                left++;
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