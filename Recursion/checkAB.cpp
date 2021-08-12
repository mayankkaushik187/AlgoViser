#include <bits/stdc++.h>
using namespace std;

int len(char s[])
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        c++;
    }
    return c;
}

bool checkhelp(char s[])
{
    if (len(s) == 0)
    {
        return true;
    }

    if (s[0] == 'a')
    {
        if (len(s + 1) > 1 && (s[1] == 'b' && s[2] == 'b'))
        {
            return checkhelp(s + 3);
        }
        else
        {
            return checkhelp(s + 1);
        }
    }

    return false;
}

bool checkAB(char input[])
{
    // Write your code here
    if (len(input) == 1 && input[0] == 'a')
    {
        return true;
    }
    return (input[0] == 'a') ? checkhelp(input) : false;
}
