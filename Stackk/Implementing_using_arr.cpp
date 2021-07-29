#include <bits/stdc++.h>
using namespace std;

//this vanilla implementation uses fixed size arrays so underflow takes place in case of peep and pop function call on an empty stack.
//Also it shows overflow behaviours in case of pushing more items than the size of the fixed array itself.
struct Stack
{
    int cap;
    int top;
    int arr[];
    Stack(int cap)
    {
        int arr[cap];
        top = -1;
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

struct myStack
{
    int cap;
    int top;
    int arr[];
    myStack(int cap)
    {
        int arr[cap];
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Exception : The stack is full cannot insert anymore elements." << endl;
        }
        top++;
        arr[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Exception : Cannot find and remove any element in the stack" << endl;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Exception : Cannot find any element in the stack" << endl;
        }
        return arr[top];
    }
    int size()
    {

        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    Stack s(5);
    cout << s.size();
}