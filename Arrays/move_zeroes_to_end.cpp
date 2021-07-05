#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> moveZeroes(vector<int> &v, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            swap(v[i], v[count]);
            count++;
        }
    }
    return v;
}
int main()
{
    vector<int> v = {1, 0, 0, 0, 0, 2, 3, 4, 0, 0, 7, 0};
    int n = v.size();
    v = moveZeroes(v, n);
    for (int e : v)
    {
        cout << e << " ";
    }
    return 0;
}