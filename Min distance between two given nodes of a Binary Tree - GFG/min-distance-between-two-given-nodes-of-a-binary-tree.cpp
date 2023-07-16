//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *first = NULL;
    void dfs(Node *root,unordered_map<Node*,Node*>&parent,Node*p)
    {
        if(root==NULL) return;
        parent[root] = p;
        dfs(root->left,parent,root);
        dfs(root->right,parent,root);
    }
    void helper(Node* root,int a)
    {
        if(root==NULL) return;
        if(root->data==a)
        {
            first = root;
        }
        helper(root->left,a);
        helper(root->right,a);
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        unordered_map<Node *,Node *>parent;
        dfs(root,parent,NULL);
        helper(root,a);
        // for(auto x : parent)
        // {
        //     if(x.second!=NULL)
        //     cout<<x.first->data<<" "<<x.second->data<<endl;
        // }
        unordered_map<Node*,bool>visited;
        queue<Node *>q;
        q.push(first);
        int ans = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto tp = q.front();
                //cout<<tp->data<<endl;
                //cout<<parent[tp]->data<<endl;
                q.pop();
                visited[tp] = true;
                if(tp->data==b) return ans;

                if(!visited[tp->left] && tp->left!=NULL) q.push(tp->left);
                if(!visited[tp->right] && tp->right!=NULL) q.push(tp->right);
                if(!visited[parent[tp]] && parent[tp]!=NULL) q.push(parent[tp]);
            }
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends