#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lRotate(vector<int> &v, int n, int d)
{
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = v[i];
    }

    for (int i = d; i < n; i++)
    {
        v[i - d] = v[i];
    }
    for (int i = 0; i < d; i++)
    {
        v[n - d + i] = temp[i];
    }

    return v;
}
int main()
{
    vector<int> v = {2, 3, 4, 5, 5, 6, 7, 1};
    int n = v.size();
    int d = 2;
    v = lRotate(v, n, d);
    for (int e : v)
    {
        cout << e << " ";
    }
    return 0;
}