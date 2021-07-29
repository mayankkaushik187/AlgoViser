#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Stack
{
    Node *head;
    int size;
    Stack()
    {
        head = NULL;
        size = 0;
    }
    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        size++;
    }
    int peek()
    {
        if (head == NULL)
        {
            cout << "Exception : The stack is empty." << endl;
        }
        return head->data;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Exception : The stack is empty." << endl;
        }
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp);
        size--;
        return res;
    }
    int size()
    {
        return size;
    }
    bool isEmpty()
    {
        return (size == 0) || (head == NULL);
    }
};