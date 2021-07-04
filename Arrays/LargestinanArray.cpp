#include <iostream>
#include <vector>
using namespace std;
int largestInAnArray(vector<int> &v)
{
    int maxIndex = 0;
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
//O(n)