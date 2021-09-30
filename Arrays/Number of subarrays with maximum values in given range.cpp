// Complete the function
#include <bits/stdc++.h>
using namespace std;

long help(int n)
{
    return n * (n + 1) / 2;
}
long countSubarrays(int arr[], int n, int L, int R)
{
    // Complete the function
    long countInc = 0;
    long countExc = 0;
    long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < L)
        {
            countInc++;
            countExc++;
        }

        else if (arr[i] > R)
        {
            res += help(countInc) - help(countExc);
            countInc = 0;
            countExc = 0;
        }
        else
        {
            res -= help(countExc);
            countInc++;
            countExc = 0;
        }
    }

    res += help(countInc) - help(countExc);

    return res;
}