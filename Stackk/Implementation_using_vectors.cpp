#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }
    int peek()
    {
        return v.back();
    }
    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }
    int size()
    {
        return v.size();
    }
    bool isEmpty()
    {
        return v.empty();
    }
};

int main()
{
    Stack s;
    s.push(50);
    cout << s.peek();
}