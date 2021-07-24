#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

bool areSame(int CT[], int CP[])
{
    for (int i = 0; i < CHAR; i++)
    {
        if (CT[i] != CP[i])
            return false;
    }
    return true;
}

bool isPresent(string &txt, string &pat)
{
    int ct[CHAR] = {0};
    int cp[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        cp[pat[i]]++;
        ct[txt[i]]++;
    }

    for (int i = pat.length(); i < txt.length(); i++)
    {
        if (areSame(ct, cp))
            return true;
        ct[txt[i]]++;
        ct[txt[i - pat.length()]]--;
    }
    return false;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat = "frog";
    if (isPresent(txt, pat))
        cout << "Anagram search found";
    else
        cout << "Anagram search not found";

    return 0;
}