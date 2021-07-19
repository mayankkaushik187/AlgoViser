#include <bits/stdc++.h>
using namespace std;

int findNumberOfTriangles(int arr[], int n)
{
    // code here
    sort(arr, arr + n);
    int count = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (arr[l] + arr[r] > arr[i])
            {
                count += r - l;

                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return count;
}