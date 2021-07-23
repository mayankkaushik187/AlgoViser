#include <bits/stdc++.h>
using namespace std;

string reverse_by_words(string &s, int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end); //reverse each word
            start = end + 1;
        }
    }
    reverse(s.begin() + start, s.begin() + n); //reverse last word
    reverse(s.begin(), s.begin() + n);         //reverse the string made by reversing the words
    return s;
}

int main()
{
    string str = "im a mad man";
    int N = str.length();
    cout << reverse_by_words(str, N);
    return 0;
}