#include <bits/stdc++.h>
using namespace std;

void maxProfit(int *arr, int n)
{
    int maxProfit = arr[n - 1];
    int price = arr[n - 1];
    sort(arr, arr + n);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] * (n - i) > maxProfit)
        {
            maxProfit = arr[i] * (n - i);
            price = arr[i];
        }
    }
    cout << maxProfit;
}

int main()
{
    int arr[5] = {34, 78, 90, 15, 67};

    maxProfit(arr, 5);
    return 0;
}