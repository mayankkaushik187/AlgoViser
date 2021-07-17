#include <bits/stdc++.h>
using namespace std;

void intersection(int a[], int b[], int n, int m)
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
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 5, 7, 8};
    int brr[] = {1, 2, 5, 7, 3, 6};
    int n = 5;
    int m = 6;
    intersection(arr, brr, n, m);
    return 0;
}