#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums) //leetcode --> 31.
{
    int i;
    for (i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }

    if (i >= 0)
    {
        //find the next larger number than nums[i] in nums[i + 1 , end];
        int j;
        for (j = nums.size() - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
            {
                break;
            }
        }
        //swap these numbers
        swap(nums[j], nums[i]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}
int main()
{
    vector<int> nums = {1, 3, 2};
    nextPermutation(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }
}