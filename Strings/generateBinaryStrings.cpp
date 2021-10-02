#include <bits/stdc++.h>
using namespace std;

void helper(string s, vector<string> &res, int index)
{
    int n = s.size();
    if (n == index)
    {
        res.push_back(s);
        return;
    }
    if (s[index] == '?')
    {
        s[index] = '0';
        helper(s, res, index);

        s[index] = '1';
        helper(s, res, index);
    }
    else
    {
        helper(s, res, index + 1);
    }
}
vector<string> generate_binary_string(string s)
{
    // Code here
    vector<string> res;
    helper(s, res, 0);

    return res;
}
