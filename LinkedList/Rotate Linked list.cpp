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
    int size(ListNode* head){
        if(!head)return 0;
        auto temp = head;
        int count = 0;
        while(temp){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or (!head -> next) or k == 0)return head;
        int length = size(head);
        k = k % length;
        if(k == 0)return head;
        ListNode* temp = head;
        for(int i = 1 ; i < length - k ; i++){
            temp = temp->next;
        }
        ListNode* rotated = temp->next;
        temp -> next = NULL;
        ListNode* tail = rotated;
        while(tail and tail -> next){
            tail = tail -> next;
        }
        if(tail)tail -> next = head;
        
        return rotated;
        
    }
};
