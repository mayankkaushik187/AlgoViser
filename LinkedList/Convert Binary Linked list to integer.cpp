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
private:
    int length(ListNode* head){
        int count = 0;
        auto temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }    
public:
    int getDecimalValue(ListNode* head) {
        int n = length(head);
        cout<<n<<"\n";
        auto temp = head;
        int ans = 0;
        while(temp){
            int data = temp->val;
            cout<<data<<"\n";
            ans += data * pow(2,--n);
            cout<<ans<<"\n";
            temp = temp->next;
        }
        return ans;
    }
};
