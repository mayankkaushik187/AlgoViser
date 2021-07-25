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

Node *insertPos(Node *head, int pos, int x)
{
    Node *temp = new Node(15);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    } //change the head
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next; //traverse
    }
    if (curr == NULL)
    {
        return head; //no changes to the list.
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
    printlist(head);
    head = insertPos(head, 2, 30);
    printlist(head);

    return 0;
}