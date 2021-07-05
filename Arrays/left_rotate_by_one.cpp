#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lRotate(vector<int> &v, int n)
{
    int temp = v[0];
    for (int i = 1; i < n; i++)
    {
        v[i - 1] = v[i];
    }
    v[n - 1] = temp;
    return v;
}
int main()
{
    vector<int> v = {2, 3, 4, 5, 5, 6, 7, 1};
    int n = v.size();
    v = lRotate(v, n);
    for (int e : v)
    {
        cout << e << " ";
    }
    return 0;
}