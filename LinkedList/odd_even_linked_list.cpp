//Leetcode 328

ListNode * oddEvenList(ListNode * head) {
    if (!head or!head -> next) return head;

    ListNode * eveptr = head -> next;
    ListNode * oddptr = head;

    ListNode * eveHead = eveptr;

    while (eveptr and eveptr -> next) {
        oddptr -> next = oddptr -> next -> next;
        eveptr -> next = eveptr -> next -> next;
        oddptr = oddptr -> next;
        eveptr = eveptr -> next;
    }

    oddptr -> next = eveHead;

    return head;

}
