#include <bits/stdc++.h>
using namespace std;
long long findSmallest(long long arr[], int n)
{
    // code here
    long long res = 1;
    for (int i = 0; i < n and arr[i] <= res; i++)
    {
        res += arr[i];
    }

    return res;
}
