#include <iostream>
#include <vector>
using namespace std;

int peak_element(vector<int> &a, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + high >> 1;
        if ((mid = 0 || a[mid - 1] <= a[mid]) && (mid == n - 1 || a[mid + 1] <= a[mid]))
        {
            return mid;
        }
        if (mid > 0 && a[mid - 1] >= a[mid])
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 10, 12, 13, 14, 16, 17, 18, 19, 24, 25, 27, 45, 57};
    int key = 16;
    int n = arr.size();
    cout << peak_element(arr, n);
    return 0;
}