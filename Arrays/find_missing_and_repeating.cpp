#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    // code here
    unordered_map<int, bool> mp;
    int *ans = new int[2];
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            ans[0] = arr[i];
        }
        else
            mp[i[arr]] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
            ans[1] = i;
    }
    return ans;
}