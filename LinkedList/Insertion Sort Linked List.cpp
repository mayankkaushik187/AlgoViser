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
    ListNode* insertionSortList(ListNode* head) {
        if(!head or !head->next)return head;
        ListNode* smallAns = insertionSortList(head->next);
        
        if(head->val <= smallAns->val){
            head->next = smallAns;
            return head;
        }
        ListNode* temp = smallAns;
        while(temp->next and head->val > temp->next->val){
            temp = temp->next;
        }
        
        head->next = temp->next;
        temp->next = head;
        return smallAns;
    }
};
