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

Node *insertAtbegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
}
int main()
{
    Node *head = NULL;
    head = insertAtbegin(head, 10);
    head = insertAtbegin(head, 20);
    head = insertAtbegin(head, 30);
    head = insertAtbegin(head, 40);
    printList(head);
    return 0;
}