#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int remDupInArr(vector<int> &v, int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[res - 1])
        {
            v[res] = v[i];
            res++;
        }
    }
    return res;
}
// v==>20 20 10 10
// 20 10

int main()
{
    vector<int> v = {1, 2, 2, 3, 3, 4, 4, 6, 6, 6};
    int n = v.size();
    int res = remDupInArr(v, n);
    for (int i = 0; i < res; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}