#include <bits/stdc++.h>
using namespace std;

int findProduct(int arr[], int n, int left, int i)
{
    //base case
    if (n == i)
    {
        return 1;
    }
    //our current element
    int curr = arr[i];

    //find the right side product
    int right = findProduct(arr, n, left * arr[i], i + 1);

    arr[i] = left * right;

    return curr * right; //have to include curr element because then the previous waiting call will not get the right answer.
}

int main()
{
    int arr[] = {5, 3, 4, 2, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findProduct(arr, n, 1, 0);

    // print the modified array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}