#include <iostream>
#include <vector>
using namespace std;

int bSearch(vector<int> &a, int low, int high, int key)
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

int siisa(vector<int> &arr, int n, int key)
{
    // if (arr[0] == key)
    // {
    //     return 0;
    // }
    // int low = 1;
    // while ((true))
    // {
    //     if (arr[low] == key)
    //     {
    //         return low;
    //     }
    //     else if (arr[low] > key)
    //     {
    //         return bSearch(arr, (low / 2) + 1, low - 1, key);
    //     }
    //     low *= 2;
    // }

    //OR===>
    if (arr[0] == key)
        return 0;

    int i = 1;

    while (arr[i] < key)
        i = i * 2;

    if (arr[i] == key)
        return i;

    return bSearch(arr, i / 2 + 1, i - 1, key);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 10, 12, 13, 14, 16, 17, 18, 19, 24, 25, 27, 45, 57};
    int key = 16;
    int n = arr.size();
    cout << siisa(arr, n, key);
    return 0;
}