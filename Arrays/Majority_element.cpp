#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &v, int n)
{
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[res] == v[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[res] == v[i])
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return res;
    }
    return -1;
}

int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = v.size();
    cout << "The majority element is at the following index : " << findMajorityElement(v, n);
    return 0;
}