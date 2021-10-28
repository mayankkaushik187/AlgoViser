//Leetcode 23
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode * mergeTwoSLL(ListNode * l1, ListNode * l2) {
            if (!l1 and l2) return l2;
            if (l1 and!l2) return l1;
            if (!l1 and!l2) return NULL;

            ListNode * dummy = new ListNode(-1);
            ListNode * prev = dummy;
            ListNode * c1 = l1, * c2 = l2;
            while (c1 and c2) {
                if (c1 -> val < c2 -> val) {
                    prev -> next = c1;
                    c1 = c1 -> next;
                } else {
                    prev -> next = c2;
                    c2 = c2 -> next;
                }
                prev = prev -> next;
            }
            prev -> next = c1 != NULL ? c1 : c2;

            return dummy -> next;
        }
    ListNode * mergeKList(vector < ListNode * > & lists, int si, int ei) {
        if (si > ei) return NULL;
        if (si == ei) return lists[si];
        int mid = (si + ei) / 2;
        ListNode * first = mergeKList(lists, si, mid);
        ListNode * second = mergeKList(lists, mid + 1, ei);

        return mergeTwoSLL(first, second);
    }
    ListNode * mergeKLists(vector < ListNode * > & lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        return mergeKList(lists, 0, lists.size() - 1);
    }
};
