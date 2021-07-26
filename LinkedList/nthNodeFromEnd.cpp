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

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printNthFromEnd(Node *head, int n)
{
    int len = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        len++;
    }
    if (len < n)
    {
        return;
    }
    Node *curr = head;
    for (int i = 1; i < len - n + 1; i++)
    {
        curr = curr->next;
    }
    cout << curr->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "Nth node from end of Linked List: ";
    printNthFromEnd(head, 2);
    return 0;
}