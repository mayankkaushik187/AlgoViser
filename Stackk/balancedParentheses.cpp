#include <bits/stdc++.h>
using namespace std;

bool balancedParentheses(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if ((st.top() == '{' && str[i] == '}') || (st.top() == '(' && str[i] == ')') || (st.top() == '[' && str[i] == ']'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string str = "((((())))){}]"; //((((())))){}]
    if (balancedParentheses(str))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}