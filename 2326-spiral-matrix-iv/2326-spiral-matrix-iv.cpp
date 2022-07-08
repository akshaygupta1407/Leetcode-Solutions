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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        bool flag = false;
        int r=0,c=0;
        int k = 0;
        n--;
        m--;
        while(r<=m && c<=n && head!=NULL)
        {
            k = c;
            while(head!=NULL && k<=n)
            {
                int x = head->val;
                head = head->next;
                res[r][k] = x;
                k++;
            }
            r++;
            k = r;
            while(head!=NULL && k<=m)
            {
                 int x = head->val;
                head = head->next;
                 res[k][n] = x;
                 k++;
            }
            n--;
            k = n;
            while(head!=NULL && k>=c)
            {
                 int x = head->val;
                head = head->next;
                 res[m][k] = x;
                 k--;
            }
            m--;
            k = m;
            
            while(head!=NULL && k>=r)
            {
                 int x = head->val;
                head = head->next;
                 res[k][c] = x;
                 k--;
            }
            c++;
        }
        return res;
    }
};