#include <bits/stdc++.h>
using namespace std;
long long sumSubstrings(string s)
{

    // your code here
    int mod = 1e9 + 7;
    vector<long long> dp(s.size() + 1, 0);

    dp[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = (((i + 1) * (s[i] - '0')) % mod + (10 * dp[i - 1]) % mod) % mod;
    }

    long long sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum = (sum + dp[i]) % mod;
    }

    return sum % mod;
}

int main()
{
    string s = "1234";
    cout << sumSubstrings(s);

    return 0;
}