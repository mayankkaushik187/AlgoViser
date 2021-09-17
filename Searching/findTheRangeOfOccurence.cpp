#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{ //leetcode 34
    vector<int> range(2, -1);
    int low = 0;
    int high = nums.size() - 1;
    //find the lower bound of our range
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == target)
        {
            range[0] = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //find the upper bound of our range
    low = 0;
    high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] == target)
        {
            range[1] = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return range;
}
int main()
{
    vector<int> nums = {1, 2, 3, 3, 3, 3, 4};
    vector<int> range = searchRange(nums, 3);

    for (int x : range)
    {
        cout << x << " ";
    }
    return 0;
}