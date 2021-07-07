#include <iostream>
#include <vector>
using namespace std;

int maxSumSub(vector<int> &v, int n)
{
    int maxSum = INT8_MIN;
    int maxNow = 0;
    for (int i = 0; i < n; i++)
    {
        maxNow = maxNow + v[i];
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

int main()
{
    vector<int> v = {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    int n = v.size();
    cout << "The max sum is " << maxSumSub(v, n);
    return 0;
}