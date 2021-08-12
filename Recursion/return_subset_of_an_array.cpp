#include <bits/stdc++.h>
using namespace std;

int subset(int input[], int n, int output[][20])
{
    // Write your code here
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallOutputSize = subset(input + 1, n - 1, output);
    // for(int i = 0 ; i < smallOutputSize ; i++){
    //     for(int k = 0 ; k <20 ; k++){
    //         copy[i][k] = output[i][k];
    //     }
    // }
    for (int i = 0; i < smallOutputSize; i++)
    {
        int number_of_columns = output[i][0];
        output[i + smallOutputSize][0] = 1 + number_of_columns;
        output[i + smallOutputSize][1] = input[0];
        for (int j = 1; j <= number_of_columns; j++)
            output[i + smallOutputSize][j + 1] = output[i][j];
    }
    return 2 * smallOutputSize;
}
