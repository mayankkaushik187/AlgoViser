#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &v, int n)
{
    int maxSum = INT8_MIN;
    int maxNow = 0;
    for (int i = 0; i < n; i++)
    {
        maxNow += v[i];

        if (maxNow > maxSum)
        {
            maxSum = maxNow;
        }
        if (maxNow < 0)
        {
            maxNow = 0;
        }
    }
    return maxSum;
}

int maxCircularSub(vector<int> &v, int n)
{
    int maxSimpleSum;
    maxSimpleSum = maxSum(v, n);
    if (maxSimpleSum < 0)
    {
        return maxSimpleSum;
    }
    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += v[i];
        v[i] = -v[i];
    }
    int max_circ = arr_sum + maxSum(v, n);

    return max(max_circ, maxSimpleSum);
}

int main()
{
    vector<int> v = {8, -4, 3, -5, 4};
    int n = v.size();
    cout << "The max sum is " << maxCircularSub(v, n);
    return 0;
}