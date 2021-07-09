#include <iostream>
#include <vector>
using namespace std;

bool eq_in_an_array(vector<int> &v, int n)
{
    int l_sum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (l_sum == sum - v[i])
        { //if the current prefix sum == suffix sum

            return true;
        }
        l_sum += v[i];
        sum -= v[i];
    }
    return false;
}