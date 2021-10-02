#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mp;
    if (t.size() != s.size())
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (mp.find(t[i]) != mp.end())
        {
            mp[t[i]]--;
        }
    }

    for (auto x : mp)
    {
        if (x.second != 0)
        {
            return false;
        }
    }

    return true;
}