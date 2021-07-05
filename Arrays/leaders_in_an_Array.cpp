#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leader1(vector<int> &v, int n) //O(N^2) Approach
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

void leader2(vector<int> &v, int n) //O(N)Time And O(N) Space Approach
{
    vector<int> res;
    res.push_back(v[n - 1]); // 1 2 3 4 2 1 2 3
    int curLdr = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > curLdr)
        {
            curLdr = v[i];
            res.push_back(curLdr);
        }
        else
        {
            continue;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 2, 1, 2, 3};
    int n = v.size();

    leader2(v, n);
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    return 0;
}