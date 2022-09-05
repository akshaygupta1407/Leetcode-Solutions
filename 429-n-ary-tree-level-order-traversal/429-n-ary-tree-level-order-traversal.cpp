/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)  return res;
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<int>curr;
            while(s--)
            {
                auto node = q.front();
                q.pop();
                curr.push_back(node->val);
                for(auto x : node->children)
                {
                    q.push(x);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};