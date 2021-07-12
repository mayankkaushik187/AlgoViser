#include <iostream>
#include <vector>
using namespace std;

bool isPalin(string str, int start, int end)
{
    //base case
    if (start >= end)
    {
        return true;
    }
    if (str[start] == str[end])
        return isPalin(str, start + 1, end - 1);
    return false;
}

int main()
{
    string str = "abccba";
    int ans;
    isPalin(str, 0, str.size() - 1) ? (ans = 1) : ans = 0;
    cout << ans << endl;
    return 0;
}