#include <bits/stdc++.h>
using namespace std;

void helper(string input, string asf)
{
    if (input.size() == 0)
    {
        cout << asf << endl;
        return;
    }
    int chv = input[0] - '0';
    char char1 = 'a' + chv - 1;
    string asf1 = asf + char1;
    helper(input.substr(1), asf1);

    if (input.size() >= 2)
    {
        int ans1 = input[0] - '0';
        int ans2 = input[1] - '0';
        int ans3 = ans1 * 10 + ans2;
        char char2 = 'a' + ans3 - 1;
        string asf2 = asf + char2;
        if (ans3 <= 26 && ans3 >= 10)
            helper(input.substr(2), asf2);
    }
}

void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */

    string asf = "";
    helper(input, asf);
}
