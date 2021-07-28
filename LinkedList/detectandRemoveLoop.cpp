#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
}

bool detectNremoveLoop(Node *head)
{
    Node *slow_p = head;
    Node *fast_p = head;
    while (fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            break;
        }
    }
    if (slow_p != fast_p)
    {
        return;
    } //till here the detection works

    slow_p = head;
    while (slow_p->next != fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }
    fast_p->next = NULL;
    //this removes the loop
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    cout << detectNremoveLoop(head);
    return 0;
}