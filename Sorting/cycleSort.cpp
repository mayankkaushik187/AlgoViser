#include <bits/stdc++.h>
using namespace std;

//this will work only for distinct elements.
void cycleSortDistinct(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }
        swap(item, arr[pos]);

        while (cs != pos)
        {
            pos = cs; // it will intialise it to the current cycle start.
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                    pos++;
            }
            swap(item, arr[pos]);
        }
    }
}

int main()
{
    int arr[] = {20, 40, 50, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSortDistinct(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}