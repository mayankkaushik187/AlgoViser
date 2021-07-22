#include <bits/stdc++.h>
using namespace std;

bool check(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    string str = "rafagasdgsdgadgadgadgqweqwe";
    cout << check(str);
    return 0;
}
