/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class BSTIterator{
        stack<TreeNode *>s;
        //reverse->before
        //!reverse->after
        bool reverse = true;
    public:
        BSTIterator(TreeNode *root,bool isReverse)
        {
            reverse = isReverse;
            pushAll(root);
        }
        bool hasNext()
        {
            return !s.empty();
        }
        int next()
        {
            TreeNode *temp = s.top();
            s.pop();
            if(!reverse)
            {
                pushAll(temp->right);
            }
            else
            {
                pushAll(temp->left);
            }
            return temp->val;
        }
    private:
        void pushAll(TreeNode *node)
        {
            for(;node!=NULL;)
            {
                s.push(node);
                if(!reverse)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }
    };
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        while(i<j)
        {
            if(i+j==k)  return true;
            else if(i+j<k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};