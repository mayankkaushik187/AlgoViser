#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &a, int key)
{
    int n = a.size();
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int mid = i + j >> 1;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 14, 24, 54, 124, 4532};
    int key = 24;
    int ans = binarySearch(arr, key);
    cout << ans + 1;

    return 0;
}