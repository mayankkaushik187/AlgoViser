#include <bits/stdc++.h>
using namespace std;

void binSort(int A[], int N)
{

    int j = -1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 1)
        {
            j++;
            swap(A[j], A[i]);
        }
    }
}