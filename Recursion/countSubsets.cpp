#include <iostream>
using namespace std;

int subsets(int arr[], int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0) ? 1 : 0;
    }
    return subsets(arr, n - 1, sum) +
           subsets(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int arr[] = {10, 20, 15};
    int n = 3;
    int sum = 25;
    int ans = subsets(arr, n, sum);
    return 0;
}