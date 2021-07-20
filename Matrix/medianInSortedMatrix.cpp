#include <bits/stdc++.h>
using namespace std;

int matMed(int mat[][100], int r, int c)
{
    int min = mat[0][0], max = mat[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];

        if (mat[i][c - 1] > max)
            max = mat[i][c - 1];
    }

    int medPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;

        for (int i = 0; i < r; ++i)
            midPos += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    int r = 3, c = 5;
    int m[][100] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    cout << "Median is " << matMed(m, r, c) << endl;
    return 0;
}