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
    ListNode* reverse(ListNode *head)
    {
        ListNode *c=head, *n = NULL, *prev = NULL;
        while(c!=NULL)
        {
            n = c->next;
            c->next = prev;
            prev = c;
            c = n;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *curr = reverse(mid);
        while(head!=NULL && curr!=NULL)
        {
            if(head->val!=curr->val)    return false;
            head = head->next;
            curr = curr->next;
        }
        return true;
    }
};