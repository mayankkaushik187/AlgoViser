#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int> &a, int low, int high, int key)
{
    //Base Case
    if (low > high)
    {
        return -1;
    }
    int mid = low + high >> 1;
    if (a[mid] < key)
    {
        return (bSearch(a, mid + 1, high, key));
    }
    else if (a[mid] > key)
    {
        return (bSearch(a, low, mid - 1, key));
    }
    return mid;
}

int main()
{
    vector<int> arr = {10, 14, 24, 54, 124, 4532};
    int n = arr.size();
    int key = 24;
    int low = 0;
    int high = n - 1;
    int ans = bSearch(arr, low, high, key);
    cout << ans;

    return 0;
}