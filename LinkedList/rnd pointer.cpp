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
    vector<int> arr;
    int n;
    Solution(ListNode* head) {
        this->n = length(head);
        auto temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }
    int length(ListNode* head){
        int count = 0;
        auto temp = head;
        while(temp){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    int getRandom() {
        int index = rand() % n;
        return arr[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
