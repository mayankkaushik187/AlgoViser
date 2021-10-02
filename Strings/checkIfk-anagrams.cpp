#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
bool areKAnagrams(string str1, string str2, int k)
{
    // code here
    if (str1.size() != str2.size())
        return false;

    unordered_map<char, int> m1;
    unordered_map<char, int> m2;

    for (int i = 0; i < str1.size(); i++)
    {
        m1[str1[i]]++;
    }
    for (int i = 0; i < str2.size(); i++)
    {
        m2[str2[i]]++;
    }
    int count = 0;
    for (auto x : m1)
    {
        if (x.second > m2[x.first])
        {
            count += x.second - m2[x.first];
        }
    }

    return count <= k;
}