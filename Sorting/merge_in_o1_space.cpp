#include <bits/stdc++.h>
using namespace std;

void merge(long long a1[], long long a2[], int n1, int n2)
{
    int i = n1 - 1;
    int j = 0;
    while (i >= 0 and j < n2)
    {
        if (a1[i] >= a2[j])
        {
            swap(a1[i--], a2[j++]);
        }
        else
        {
            i--;
        }
    }

    sort(a1, a1 + n1);
    sort(a2, a2 + n2);
}