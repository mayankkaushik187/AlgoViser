Node * copyRandomList(Node * head) {
    if (!head) return NULL;
    Node * temp = head;
    while (temp) {
        Node * nxt = temp -> next;
        temp -> next = new Node(temp -> val);
        temp -> next -> next = nxt;
        temp = nxt;
    }
    temp = head;
    while (temp) {
        if (temp -> random)
            temp -> next -> random = temp -> random -> next;
        temp = temp -> next -> next;
    }
    temp = head;
    Node * copyHead = head -> next;
    Node * copyTemp = copyHead;

    while (copyTemp -> next) {
        temp -> next = temp -> next -> next;
        temp = temp -> next;

        copyTemp -> next = copyTemp -> next -> next;
        copyTemp = copyTemp -> next;
    }
    temp -> next = temp -> next -> next;

    return copyHead;

}
