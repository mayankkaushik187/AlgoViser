#include <bits/stdc++.h>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int curr = 1;
    for (int i = 1; i < n;)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] == arr[j - 1])
            {
                curr++;
            }
            else
            {
                i = j;
                break;
            }
            if (curr > (n / k))
            {
                cout << arr[j - 1] << " ";
            }
        }
    }
}

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printNByK(arr, n, k);
}