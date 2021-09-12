#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int palindromePartitioning_Recur(string s, int i, int j)
{
    if (isPalindrome(s, i, j))
    {
        return 0;
    }
    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        res = min(res, palindromePartitioning_Recur(s, i, k) + palindromePartitioning_Recur(s, k + 1, j) + 1);
    }

    return res;
}