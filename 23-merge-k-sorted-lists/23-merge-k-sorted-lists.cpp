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
    ListNode *merge(ListNode *a,ListNode *b)
    {
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode *newhead;
        if(a->val < b->val)
        {
            newhead = a;
            ListNode *c = merge(a->next,b);
            newhead->next = c;
        }
        else
        {
            newhead = b;
            ListNode *d = merge(a,b->next);
            newhead->next = d;
        }
        return newhead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1)  return lists[0];
        ListNode *l1 = lists[0];
        for(int i=1;i<lists.size();i++)
        {
            l1 = merge(l1,lists[i]);
        }
        return l1;
    }
};