#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leader(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] <= v[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << v[i] << " ";
        }
    }
}

int main()
{
    vector<int> v = {2, 3, 4, 5, 5, 6, 7, 1};
    int n = v.size();

    leader(v, n);
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    return 0;
}