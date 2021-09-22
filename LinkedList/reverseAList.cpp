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

Node *reverseList(Node *head)
{
    if(!head)return NULL;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;

    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "Reversed Linked List: ";
    head = reverseList(head);
    printlist(head);
    return 0;
}
