#include <bits/stdc++.h>
using namespace std;

string combs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
    {
        return {};
    }
    vector<string> res;
    res.push_back("");
    for (auto digit : digits)
    {
        vector<string> temp;
        for (auto comb : combs[digit - '0'])
        {
            for (auto s : res)
            {
                temp.push_back(s + comb);
            }
        }
        res.swap(temp);
    }
    return res;
}