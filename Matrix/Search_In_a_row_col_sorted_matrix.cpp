#include <bits/stdc++.h>
using namespace std;
//Searches in a row and column wise sorted matrix and returns 1 if element is present otherwise -1;
int search(vector<vector<int>> v, int k)
{
    int row = v.size();
    int col = v[0].size();

    if ((k > v[row - 1][col - 1]) || (k < v[0][0]))
    {
        return -1;
    }

    int i = 0;
    int j = col - 1;
    while (i < row && j >= 0)
    {
        if (v[i][j] == k)
        {
            return 1;
        }
        else if (v[i][j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << search(v, 50);
    return 0;
}