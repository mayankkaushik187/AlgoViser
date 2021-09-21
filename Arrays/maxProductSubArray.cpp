#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long maxProduct(vector<int> arr, int n)
{
    // code here
    ll maxVal = arr[0];
    ll minVal = arr[0];
    ll maxProd = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxVal, minVal);
        }

        minVal = min<ll>(arr[i], minVal * arr[i]);
        maxVal = max<ll>(arr[i], maxVal * arr[i]);

        maxProd = max(maxProd, maxVal);
    }
    return maxProd;
}