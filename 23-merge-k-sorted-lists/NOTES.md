```
class Solution {
public:
ListNode* merge(ListNode *a,ListNode *b)
{
if(a==NULL)
{
return b;
}
if(b==NULL)
{
return a;
}
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
int n = lists.size();
if(n==0)
{
return NULL;
}
if(n==1)
{
ListNode *head = lists[0];
return head;
}
ListNode *point1 = lists[0];
ListNode *point2 = NULL;
for(int i=1;i<n;i++)
{
point2 = lists[i];
point1 = merge(point1,point2);
}
return point1;
}
};
```