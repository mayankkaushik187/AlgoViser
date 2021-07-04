#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &v, int n) // O(N)
{
    if (n == 1)
    {
        return true;
    }

    for (int i = 1; i < n; i++)
    {

        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
}