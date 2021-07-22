#include <bits/stdc++.h>
using namespace std;

bool check(string str1, string str2)
{
    int i = 0;
    int j = 0;
    int n = str1.length();
    int m = str2.length();
    int minSize = min(n, m);
    while (i != n && j != m)
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j == m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    string str1 = "ABCD";
    string str2 = "AD";
    cout << check(str1, str2);
    return 0;
}
