#include <iostream>
#include <vector>
using namespace std;

//Given a sorted Binary array find the count of 1's
int count_ones(vector<int> &a, int n)
{
    int index = 0;
    for (int i = 0; i < n; i++) //O(N)
    {

        if (a[i] == 1)
        {
            index = i;
            break;
        }
    }
    return n - index;
}

int count_ones_bSearch(vector<int> &a, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + high >> 1;
        if (a[mid] == 0)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0 || a[mid - 1] != a[mid])
            {
                return n - mid;
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
    vector<int> arr = {0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = arr.size();

    cout << count_ones_bSearch(arr, n);

    return 0;
}