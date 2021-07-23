#include <bits/stdc++.h>
using namespace std;

bool check(const string &str1, const string &str2)
{
    int i = 0;
    int j = 0;
    int n = str1.length();
    int m = str2.length();
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
//Recursive Approach

bool recCheck(string &str1, string &str2, int n, int m)
{
    //Base case
    if (m == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (str1[n - 1] == str2[m - 1])
    {
        return recCheck(str1, str2, n - 1, m - 1);
    }
    else
    {
        return recCheck(str1, str2, n - 1, m);
    }
}

int main()
{
    string str1 = "ABCD";
    string str2 = "AD";
    cout << check(str1, str2);
    return 0;
}
// O(n+m) --> time
//O(1) --> space
