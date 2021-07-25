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

int searchLL(Node *head, int x) // iterative
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return pos;
        }
        pos++;
        curr = curr->next;
    }
    return -1;
}

int searchLLRec(Node *head, int pos, int x) // Recursive
{
    if (head == NULL)
    {
        return -1;
    }
    Node *curr = head;
    if (curr->data == x)
    {
        return pos;
    }
    else
    {
        return searchLLRec(curr->next, pos + 1, x);
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    cout << "the position is : " << searchLLRec(head, 1, 50);

    return 0;
}