#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    int n = strs.size();
    unordered_map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].push_back(str);
    }

    for (auto x : mp)
    {
        res.push_back(x.second);
    }

    return res;
}