```
class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
ListNode *dummy = new ListNode(-1);
dummy->next = head;
ListNode *front = dummy,*back = dummy;
for(int i=1;i<=n;i++)
{
front = front->next;
}
while(front->next!=NULL)
{
front = front->next;
back = back->next;
}
back->next = back->next->next;
return dummy->next;
}
};
```