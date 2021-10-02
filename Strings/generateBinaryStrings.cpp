#include <bits/stdc++.h>
using namespace std;
//recursive approach
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
//queue based approach

vector<string> generate_binary_string(string s)
{
    // Code here
    queue<string> q;
    q.push(s);
    vector<string> res;
    while (!q.empty())
    {
        auto str = q.front();
        int index = str.find('?');
        if (index != string::npos)
        {
            str[index] = '0';
            q.push(str);

            str[index] = '1';
            q.push(str);
        }
        else
        {
            res.push_back(str);
        }

        q.pop();
    }

    return res;
}
