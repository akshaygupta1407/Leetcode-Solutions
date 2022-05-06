class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        stack<pair<char,int>>stack;
        for(int i=0;i<n;i++)
        {
            if(stack.empty() || s[i]!=stack.top().first)
            {
                stack.push({s[i],1});
            }
            else
            {
                auto temp = stack.top();
                stack.pop();
                stack.push({s[i],temp.second + 1});
            }
            if(stack.top().second==k)
            {
                stack.pop();
            }
        }
        string ans = "";
        while(!stack.empty())
        {
            auto temp = stack.top();
            stack.pop();
            while(temp.second--)
            {
                ans+=temp.first;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};