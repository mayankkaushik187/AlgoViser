#include <iostream>
using namespace std;
bool compare(char arr1[], char arr2[])
{
    for (int i = 0; i < 256; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }

    return true;
}
int search(string pat, string txt)
{
    char patC[256] = {0}, txtC[256] = {0};
    int n = pat.size(), m = txt.size();
    for (int i = 0; i < n; i++)
    {
        patC[pat[i]]++;
        txtC[txt[i]]++;
    }
    int count = 0;
    for (int i = n; i < m; i++)
    {
        if (compare(patC, txtC))
        {
            count++;
        }
        txtC[txt[i]]++;
        txtC[txt[i - n]]--;
    }
    if (compare(patC, txtC))
    {
        count++;
    }
    return count;
}