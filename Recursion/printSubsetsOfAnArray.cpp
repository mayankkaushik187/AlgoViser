#include <bits/stdc++.h>
using namespace std;

void printSubs(int input[], int size, int output[], int sizeOut)
{
    if (size == 0)
    {
        for (int i = 0; i < sizeOut; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    printSubs(input + 1, size - 1, output, sizeOut);
    int copy[sizeOut + 1];
    int i = 0;
    for (i = 0; i < sizeOut; i++)
    {
        copy[i] = output[i];
    }
    copy[i] = input[0];
    printSubs(input + 1, size - 1, copy, sizeOut + 1);

    return;
}

void printSubsetsOfArray(int input[], int size)
{
    // Write your code here
    int *output = new int[0];
    int sizeOut = 0;
    printSubs(input, size, output, sizeOut);
}