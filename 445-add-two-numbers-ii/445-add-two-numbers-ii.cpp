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
    stack<int>s1,s2;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1!=NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0,carry = 0;
        ListNode *list = NULL;
        while(!s1.empty() || !s2.empty())
        {
            int x = s1.empty() ? 0 : s1.top();
            if(!s1.empty())
            s1.pop();
            int y = s2.empty() ? 0 : s2.top();
            if(!s2.empty())
            s2.pop();
            sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;
            ListNode *dummy = new ListNode(sum);
            dummy->next = list;
            list = dummy;
        }
        if(carry)
        {
            ListNode *dummy = new ListNode(carry);
            dummy->next = list;
            list = dummy;
        }
        return list;
    }
};