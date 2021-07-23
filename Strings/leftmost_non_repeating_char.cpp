#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;
int nonRep(string &str)
{
    int fIndex[CHAR];
    int res = INT_MAX;
    fill(fIndex, fIndex + CHAR, -1);
    for (int i = 0; i < str.length(); i++)
    {
        if (fIndex[str[i]] == -1)
        {
            fIndex[str[i]] = i;
        }
        else
        {
            fIndex[str[i]] = -2;
        }
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (fIndex[i] >= 0)
        {
            res = min(res, fIndex[i]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string str = "geeksforgeeks";
    cout << "Index of leftmost non-repeating element:" << endl;
    cout << nonRep(str) << endl;

    return 0;
}