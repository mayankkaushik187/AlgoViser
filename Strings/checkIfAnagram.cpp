#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string &str1, string &str2, int n, int m)
{

    if (n != m)
        return 0;
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[str1[i]]++;
        freq[str2[i]]--;
    }
    // for (int i = 0; i < m; i++)
    // {
    //     if (freq.find(str2[i]) != freq.end())
    //     {
    //         freq[str2[i]]--;
    //     }
    // }
    for (auto x : freq)
    {
        if (x.second > 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string str1 = "liste";
    string str2 = "silen";
    int n = str1.length();
    int m = str2.length();
    cout << checkAnagram(str1, str2, n, m);
    return 0;
}