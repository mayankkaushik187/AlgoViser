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

void printCLL(Node *head)
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

Node *deleteHeadCLL(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

Node *deleteKthCLL(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (k == 0)
        return head;
    if (k == 1)
    {
        return deleteHeadCLL(head);
    }
    Node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = deleteKthCLL(head, 1);
    printCLL(head);

    return 0;
}