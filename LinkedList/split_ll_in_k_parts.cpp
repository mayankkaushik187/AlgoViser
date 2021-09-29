#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> res(k, NULL);
    int count = 0;
    for (ListNode *curr = head; curr; curr = curr->next)
    {
        count++;
    }
    int n = count / k, r = count % k;
    ListNode *temp = head, *prev = NULL;

    for (int i = 0; temp and i < k; i++, r--)
    {
        res[i] = temp;
        for (int j = 0; j < n + (r > 0); j++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
    }

    return res;
}