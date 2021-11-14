#include <bits/stdc++.h>
using namespace std;
//Leetcode Soln
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k == 1)return head;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        auto prev = dummy, curr = dummy, nex = dummy;
        //count the number of nodes
        int count = 0;
        while(curr->next != NULL){
            curr = curr->next;
            count++;
        }
        while(count >= k){
            curr = prev->next;
            nex = curr->next;
            for(int i = 0 ; i < k - 1 ; i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            count -= k;
            prev = curr;
        }
        return dummy->next;
    }
};

//_______________________________________________________________
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *reverseInK(Node *head, int k)
{
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(30);
    printlist(head);
    cout << "Final Linked List: ";
    int k = 3;
    head = reverseInK(head, k);
    printlist(head);
    return 0;
}
