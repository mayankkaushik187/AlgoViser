//Leetcode 143
void reorderList(ListNode * head) {
  if (!head || (!head -> next) || (!head -> next -> next)) return;
  stack < ListNode * > stk;
  ListNode * temp = head;
  while (temp) {
    stk.push(temp);
    temp = temp -> next;
  }
  ListNode * pptr = head;
  int size = stk.size();
  for (int i = 0; i < size / 2; i++) {
    auto topEle = stk.top();
    stk.pop();
    topEle -> next = pptr -> next;
    pptr -> next = topEle;
    pptr = pptr -> next -> next;
  }
  pptr -> next = NULL;
}
