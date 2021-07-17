#include <bits/stdc++.h>
using namespace std;

void unionOfArrs(int a[], int b[], int n, int m)
{
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (i > 0 && a[i] != a[i - 1])
            cout << a[i++] << " ";
    }
    while (j < m)
    {
        if (j > 0 && b[j] != b[j - 1])
            cout << b[j++] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 2, 3, 4};
    int brr[] = {1, 2, 5, 7, 8, 9};
    int n = 5;
    int m = 6;
    unionOfArrs(arr, brr, n, m);
    return 0;
}