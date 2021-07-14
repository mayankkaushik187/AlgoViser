#include <bits/stdc++.h>
using namespace std;

// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    int n = arr_size;
    //sort the array
    sort(A, A + n);
    for (int i = 0; i < n - 3; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            if (A[low] + A[high] + A[i] == sum)
            {
                cout << A[i] << " " << A[low] << " " << A[high] << " " << endl;
                return true;
            }
            else if (A[low] + A[high] + A[i] > sum)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    } // O(N^2) time Complexity
    //no triplet found
    return false;
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);

    find3Numbers(A, arr_size, sum);

    return 0;
}
