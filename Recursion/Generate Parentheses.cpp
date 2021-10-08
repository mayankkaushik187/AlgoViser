#include <bits/stdc++.h>
using namespace std;
//Leetcode 22
void helper(int open, int close, vector<string> &res, stack<char> s, int n)
{
    if (open == close and close == n)
    {
        string str = "";
        while (!s.empty())
        {
            str += s.top();
            s.pop();
        }
        reverse(str.begin(), str.end());
        res.push_back(str);
    }
    if (open < n)
    {
        s.push('(');
        helper(open + 1, close, res, s, n);
        s.pop();
    }
    if (close < open)
    {
        s.push(')');
        helper(open, close + 1, res, s, n);
        s.pop();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    stack<char> s;
    helper(0, 0, res, s, n);
    return res;
}