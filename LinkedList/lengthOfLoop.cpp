//Function to find the length of a loop in the linked list.
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
int countNodesHelper(Node *ptr)
{
    int count = 1;
    Node *temp = ptr;
    while (temp->next != ptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
int countNodesinLoop(Node *head)
{
    // Code here
    if (head == NULL || head->next == NULL)
        return 0;

    Node *fast = head;
    Node *slow = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return countNodesHelper(slow);
        }
    }

    return 0;
}