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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode *newhead;
        if(a->val < b->val)
        {
            newhead = a;
            ListNode *c = mergeTwoLists(a->next,b);
            newhead->next = c;
        }
        else
        {
            newhead = b;
            ListNode *d = mergeTwoLists(a,b->next);
            newhead->next = d;
        }
        return newhead;
    }
};