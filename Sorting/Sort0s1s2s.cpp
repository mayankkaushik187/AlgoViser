#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int ar[] = {0, 1, 2, 1, 0, 1, 2, 1};
    int n = 8;
    sort012(ar, n);
    for (auto e : ar)
    {
        cout << e << " ";
    }
    return 0;
}