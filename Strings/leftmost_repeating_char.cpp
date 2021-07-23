#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;
int leftMost(string &str)
{
    int fIndex[CHAR];
    // for (int i = 0; i < str.length(); i++)
    // {
    //     count[str[i]]++;
    // }
    // for (int i = 0; i < str.length(); i++)
    // {
    //     if (count[str[i]] > 1)
    //     {
    //         return i;
    //     }
    // }
    // return -1;
    fill(fIndex, fIndex + CHAR, -1);
    int res = INT_MAX;                     // We have to find the minimum thats why we us INT_MAX
    for (int i = 0; i < str.length(); i++) // fill the fIndex arr and then if the value for a character index is -1 change it to the index in the actual string else if the element has been encountered before then minimise the res with current fi.
    {
        int fi = fIndex[str[i]];
        if (fi == -1)
        {
            fIndex[str[i]] = i;
        }
        else
        {
            res = min(res, fi);
        }
    }
    return (res == INT_MAX) ? -1 : res; //if we never encounter duplicates then just return -1 else return the res;
}

int main()
{
    string str = "geeksforgeeks";
    cout << "Index of leftmost repeating character:" << endl;
    cout << leftMost(str) << endl;

    return 0;
}