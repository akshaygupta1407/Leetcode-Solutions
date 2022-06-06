```
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
ListNode *currA = headA,*currB = headB;
if(currA==NULL || currB==NULL)
return NULL;
while(currA!=currB)
{
currA = currA->next;
currB = currB->next;
if(currA==currB)
return currA;
if(currA==NULL)
currA = headB;
if(currB==NULL)
currB = headA;
}
return currA;
}
};
```