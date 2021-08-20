struct Node *pairwise_swap(struct Node *head)
{
    // your code here
    if (head == NULL || head->next == NULL)
        return head;
    Node *nextNode = head->next;
    Node *now = head;

    while (now && nextNode)
    {
        swap(nextNode->data, now->data);
        now = nextNode->next;
        if (now)
            nextNode = now->next;
    }

    return head;
}