#include <bits/stdc++.h>
using namespace std;

void helper(string str, int k, string &max, int count)
{
    if (k == 0)
    {
        return;
    }
    int n = str.size();
    char maxm = str[count];
    for (int j = count + 1; j < n; j++)
    {
        if (maxm < str[j])
        {
            maxm = str[j];
        }
    }

    if (maxm != str[count])
    {
        --k;
    }

    for (int j = n - 1; j >= count; j--)
    {
        if (str[j] == maxm)
        {
            swap(str[j], str[count]);
            if (str.compare(max) > 0)
            {
                max = str;
            }

            helper(str, k, max, count + 1);

            swap(str[j], str[count]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string max = str;
    helper(str, k, max, 0);

    return max;
}
