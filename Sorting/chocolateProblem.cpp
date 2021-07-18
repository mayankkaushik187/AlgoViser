#include <bits/stdc++.h>
using namespace std;

int chocoProblem(int arr[], int n, int m)
{
    if (m > n)
        return -1; // edge case
    int minDiff = 0;
    sort(arr, arr + n);
    int res = 0;
    int currDiff = 0;
    minDiff = arr[m - 1] - arr[0];
    for (int i = m; i < n; i++)
    {
        currDiff = arr[i] - arr[i - m + 1];
        minDiff = min(minDiff, currDiff);
    }
    return minDiff;
}

// 1 3 4 5 7 9

int main()
{
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = 7;
    int m = 3;
    cout << chocoProblem(arr, n, m);
    return 0;
}