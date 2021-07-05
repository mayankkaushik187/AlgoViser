#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDiff(vector<int> &v, int n) //O(N^2) Approach
{
    int res = v[1] - v[0];
    int minVal = v[0];
    for (int j = 1; j < n; j++)
    {
        res = max(res, v[j] - minVal);
        minVal = min(minVal, v[j]);
    }
    return res;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 2, 1, 2, 3};
    int n = v.size();

    cout << maxDiff(v, n);
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    return 0;
}