#include <bits/stdc++.h>
using namespace std;

int count_n_bsts(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int lans = count_n_bsts(i - 1);
        int rans = count_n_bsts(n - i);

        res += lans * rans;
    }

    return res;
}

int count_n_bsts_dp(int n)
{
    vector<int> dp(n + 1, 0);
}

int main()
{
    int n = 4;
    cout << count_n_bsts(n);
    return 0;
}