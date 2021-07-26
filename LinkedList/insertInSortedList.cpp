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
    if (head == NULL)
        return;
    Node *curr = head;
    do
    {
        cout << curr->data;
        curr = curr->next;
    } while (curr != head);
}

Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }
    if (head->data > x)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < x)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = insert(head, 25);
    printList(head);

    return 0;
}