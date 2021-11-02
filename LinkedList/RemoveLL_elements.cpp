
ListNode * removeElements(ListNode * head, int val) {
    if (head == NULL) return NULL;
    ListNode * next = removeElements(head -> next, val);
    /*if head was the val then just return whatever recursion returned to us*/
    if (head -> val == val) {
        return next;
    }
    //otherwise connect the head to the next ll which recursion gave us and return head
    head -> next = next;
    return head;
}
