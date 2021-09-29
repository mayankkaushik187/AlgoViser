#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums) //TC _ O(n) SC _ O(1)
{
    int i = 0, j = 1, n = nums.size();

    while (i < n && j < n)
    {
        while (i < n and nums[i] % 2 == 0)
        {
            i += 2;
        }
        while (j < n and nums[j] % 2 == 1)
        {
            j += 2;
        }
        if (i < n and j < n)
        {
            swap(nums[i], nums[j]);
        }
    }

    return nums;
}

vector<int> sortArrayByParityII(vector<int> &nums) //TC _O(n) SC _ O(n)
{
    //to store the odd nums[i] with even indices
    stack<pair<int, int>> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0 and i % 2 == 0)
        {
            mp.push({nums[i], i});
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0 and i % 2 != 0)
        {
            swap(nums[i], nums[mp.top().second]);
            mp.pop();
        }
    }

    return nums;
}