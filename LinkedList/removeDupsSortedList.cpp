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
//Remove duplioates from a linked list
Node *remDups(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        Node *next = curr->next;
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
            delete next;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    printlist(head);
    cout << "Final Linked List: ";
    head = remDups(head);
    printlist(head);
    return 0;
}
