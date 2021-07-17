#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min_ind = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        swap(arr[i], arr[min_ind]);
    }
}

int main()
{
    int arr[] = {1, 4, 2, 3, 6, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int e : arr)
    {
        cout << e << " ";
    }
}

//  1 4 2 3 6 8 5