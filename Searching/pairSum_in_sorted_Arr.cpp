#include <bits/stdc++.h>

using namespace std;

bool isPresent(int arr[], int arr_size, int sum)
{
    int low = 0;
    int high = arr_size - 1;
    while (low < high)
    {
        if ((arr[low] + arr[high]) == sum)
        {
            return true;
        }
        else if ((arr[low] + arr[high]) > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    // Function calling
    isPresent(A, arr_size, n) ? cout << "1" : cout << "0";

    return 0;
}