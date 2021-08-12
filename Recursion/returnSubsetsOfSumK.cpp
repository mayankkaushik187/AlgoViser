#include <bits/stdc++.h>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int o1[1000][50], o2[1000][50];
    int x = subsetSumToK(input + 1, n - 1, o1, k);
    int y = subsetSumToK(input + 1, n - 1, o2, k - input[0]);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= 50; j++)
            output[i][j] = o1[i][j];
    }
    for (int i = 0; i < y; i++)
    {
        int number_of_columns = o2[i][0];
        output[i + x][0] = 1 + number_of_columns;
        output[i + x][1] = input[0];
        for (int j = 1; j <= number_of_columns; j++)
            output[i + x][j + 1] = o2[i][j];
    }

    return x + y;
}
