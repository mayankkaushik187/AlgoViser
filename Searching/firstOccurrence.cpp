#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> &a, int low, int high, int key)
{
    //Generic Binary search
    if (low > high)
        return -1; // Key Not found
    int mid = low + high >> 1;
    if (a[mid] > key)
    {
        return firstOcc(a, low, mid - 1, key);
    }
    else if (a[mid] < key)
    {
        return firstOcc(a, mid + 1, low, key);
    }
    //First occurrence code
    else
    {
        if (mid == 0 || a[mid - 1] != a[mid])
        {
            return mid;
        }
        else
        {
            return firstOcc(a, low, mid - 1, key); //this will search for the first occurrence on the left of the key element.
        }
    }
    return mid;
}

int main()
{
    vector<int> arr = {10, 10, 20, 20, 20, 30, 40};
    int n = arr.size();
    int key = 30;
    int low = 0;
    int high = n - 1;
    int ans = firstOcc(arr, low, high, key);
    cout << ans + 1; //position not index

    return 0;
}