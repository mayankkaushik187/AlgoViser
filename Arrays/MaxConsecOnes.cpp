#include <iostream>
#include <vector>
using namespace std;

int maxOnes(vector<int> &v, int n)
{
    int count = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            res = max(res, count);
        }
    }
    return count;
}

int main()
{
    vector<int> v = {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    int n = v.size();
    cout << "The max no. of consecutive ones are " << maxOnes(v, n);
    return 0;
}