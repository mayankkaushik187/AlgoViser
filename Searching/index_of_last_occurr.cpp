#include <iostream>
#include <vector>
using namespace std;

int lastOccur(vector<int> &a, int low, int high, int key, int n)
{
    //Generic Binary Search

    while (low <= high)
    {

        int mid = low + high >> 1;
        if (a[mid] == key)
        {
            if (mid == n - 1 || a[mid + 1] != a[mid])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 24, 24, 54, 124, 4532};
    int n = arr.size();
    int key = 24;
    int low = 0;
    int high = n - 1;
    int ans = lastOccur(arr, low, high, key, n);
    cout << ans;

    return 0;
}