#include <bits/stdc++.h>
using namespace std;

const int max_char = 26;
string hashIt(string str)
{
    vector<bool> vis(max_char, false);
    string res = "";
    for (int i = 0; i < str.size(); i++)
    {
        vis[str[i] - 'a'] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (vis[i])
        {
            res += char('a' + i);
        }
    }

    return res;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    int n = strs.size();
    unordered_map<string, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        string curr = hashIt(strs[i]);
        mp[curr].push_back(i);
    }
    int index = 0;
    for (auto x : mp)
    {
        vector<string> curr;
        for (auto y : x.second)
        {
            curr.push_back(strs[y]);
        }
        res.push_back(curr);
    }

    return res;
}