#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int brr[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (arr[i] <= brr[j])
        {
            cout << arr[i] << " ";
            i++;
        }
        else
        {
            cout << brr[j] << " ";
            j++;
        }
    }
    while (i < m)
    {
        cout << arr[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << brr[j] << " ";
        j++;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {4, 5, 6, 9};
    int m = 4;
    int n = 4;
    merge(a, b, m, n);
    return 0;
}
