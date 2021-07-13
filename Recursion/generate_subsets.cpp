#include <iostream>
using namespace std;

void genSubs(string str, string curr, int idx)
{
    //base case
    if (idx == str.length())
    {
        cout << curr << " ";
        return;
    }

    //recursive case

    genSubs(str, curr, idx + 1);
    genSubs(str, curr + str[idx], idx + 1);
}

int main()
{

    string str = "ABC";
    string curr = "";
    int idx = 0;
    genSubs(str, curr, idx);
    return 0;
}
