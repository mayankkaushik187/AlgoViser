#include <bits/stdc++.h>
using namespace std;

int subsequences(string s, string output[])
{
    if (s.empty())
    {
        output[0] = "";
        return 1;
    }

    int smallOutputSize = subsequences(s.substr(1), output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = s[0] + output[i];
    }

    return 2 * smallOutputSize;
}

int main()
{
    string str;
    cin >> str;
    int length = str.size();
    int sizeOfArr = pow(2, length);
    string *output = new string[1000];

    int outputSize = subsequences(str, output);
    for (int i = 0; i < outputSize; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}