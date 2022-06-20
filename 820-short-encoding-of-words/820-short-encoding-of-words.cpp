class Solution {
public:
    struct TrieNode{
      TrieNode* children[26]{};
        int count{};
        TrieNode *get(char c)
        {
            //already inserted
            if(children[c-'a']) return children[c-'a'];
            else
            {
                count++;
                return children[c-'a'] = new TrieNode();
            }
        }
    };
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode();
        unordered_map<TrieNode*,int>res;
        for(auto &w : words)
        {
            TrieNode *curr = root;
            for(int i=w.size()-1;i>=0;i--)
            {
                curr = curr->get(w[i]);
            }
            if(curr->count==0)  res[curr] = w.size()+1;
        }
        int ans = 0;
        for(auto x : res)
        {
            if(x.first->count==0)   ans+=x.second;

        }
        return ans;
    }
};