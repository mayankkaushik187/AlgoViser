#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string str;
    cin >> str;
 
    int maxLen = 1;
    int len = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
        {
            len++;
            if (len > maxLen)
            {
                maxLen = len;
            }
        }
        else
        {
            len = 1;
        }
    }
    cout << maxLen << "\n";
 
    return 0;
}
