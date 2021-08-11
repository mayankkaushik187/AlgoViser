#include <bits/stdc++.h>
using namespace std;

void print_subs(string s, string res)
{
    //Base Case

    if (s.empty())
    {
        cout << res << endl;
        return;
    }

    //recursive case
    print_subs(s.substr(1), res);
    print_subs(s.substr(1), res + s[0]);
}

int main()
{
    string s = "abc";
    string res = "";
    print_subs(s, res);
    return 0;
}