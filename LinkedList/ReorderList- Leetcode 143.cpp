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
    void reorderList(ListNode* head) {
        if(!head or !head -> next or !head->next->next){
            return ;
        }
        //find the penultimate node
        auto penultimate = head;
        while(penultimate -> next -> next){
            penultimate = penultimate -> next;
        }
        penultimate -> next -> next = head->next;
        // penultimate -> next = NULL;
        head->next = penultimate -> next;
        penultimate->next = NULL;
        reorderList(head->next->next);
    }
};
