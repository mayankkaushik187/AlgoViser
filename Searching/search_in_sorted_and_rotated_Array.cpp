#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSorted(vector<int> &a, int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + high >> 1;
        if (a[mid] >= a[low])
        {
            //so our elelment lies between low and current mid
            if (a[mid] == key)
            {
                return mid;
            }
            else if (key < a[mid] && key >= a[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (a[mid] <= a[high])
        {
            if (a[mid] == key)
            {
                return mid;
            }
            else if (key <= a[high] && key > a[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 10, 12, 13, 14, 16, 17, 18, 19, 24, 25, 27, 45, 57};
    int key = 16;
    int n = arr.size();
    cout << searchInRotatedSorted(arr, n, key);
    return 0;
}