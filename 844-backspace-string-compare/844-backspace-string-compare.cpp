class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        for(auto x : s)
        {
            if(x=='#' && !s1.empty())
            {
                s1.pop();
            }
            else if(x!='#')
            {
                s1.push(x);
            }
        }
        for(auto x : t)
        {
            if(x=='#' && !s2.empty())
            {
                s2.pop();
            }
            else if(x!='#')
            {
                s2.push(x);
            }
        }
        s = "",t = "";
        while(!s1.empty())
        {
            char c = s1.top();
            s1.pop();
            s+=c;
        }
        while(!s2.empty())
        {
            char c = s2.top();
            s2.pop();
            t+=c;
        }
        cout<<s<<" "<<t<<endl;
        return s==t;
    }
};