#include <iostream>
#include <vector>
using namespace std;

int sqrt_bsearch(int n)
{
    int low = 1;
    int high = n;
    int ans = -1;

    if (n == 0)
    {
        return 0;
    }

    while (low <= high)
    {
        int mid = low + high >> 1;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = arr.size();

    cout << sqrt_bsearch(n);

    return 0;
}