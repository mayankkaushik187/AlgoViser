#include <bits/stdc++.h>
using namespace std;

int subset_sum_recur(int arr[], int n, int sum)
{
    if (n == 0)
    {
        return sum == 0 ? 1 : 0;
    }

    return subset_sum_recur(arr, n - 1, sum) + subset_sum_recur(arr, n - 1, sum - arr[n - 1]);
}

int subset_sum_dp(int arr[], int n, int sum)
{
}

int main()
{
    int n = 4;
    int arr[] = {10, 20, 15, 2};
    cout << "Recursion = " << subset_sum_recur(arr, n, 25) << endl;
}