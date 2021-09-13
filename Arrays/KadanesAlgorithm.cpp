#include <bits/stdc++.h>
using namespace std;

long long maximumSum(int arr[], int sizeOfArray)
{
    //code here
    long long maxNow = 0;
    long long maxSum = INT_MIN;
    int n = sizeOfArray;
    for (int i = 0; i < n; i++)
    {
        maxNow += arr[i];

        if (maxNow > maxSum)
        {
            maxSum = maxNow;
        }
        cout << maxNow << " ";
        if (maxNow < 0)
        {
            maxNow = 0;
        }
    }
    cout << endl;
    return maxSum;
}
int main()
{
    int arr[] = {5, -2, -3, 32, -5, 65};
    int n = 6;
    cout << maximumSum(arr, n);

    return 0;
}