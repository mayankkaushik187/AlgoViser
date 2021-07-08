#include <iostream>
#include <vector>
using namespace std;

int longest_even_odd(vector<int> &v, int n)
{
    int prev = v[0];
    int count = 1;
    int res = 1;
    // 1 4 3 6 5
    for (int i = 1; i < n; i++)
    {
        if ((v[i] % 2 == 0 && prev % 2 != 0) || v[i] % 2 != 0 && prev % 2 == 0)
        {

            count++;
            res = max(count, res);
        }
        else if ((v[i] % 2 != 0 && prev % 2 != 0))
        {
            count = 1;
            continue;
        }
        else if ((v[i] % 2 == 0 && prev % 2 == 0))
        {
            count = 1;
            continue;
        }
        prev = v[i];
    }
    return res;
}

int main()
{
    vector<int> v = {5, 10, 20, 6, 3, 8};
    int n = v.size();
    cout << "The max length is " << longest_even_odd(v, n);
    return 0;
}