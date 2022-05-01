//without using stack
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1 = "",res2="";
        int i = 0;
        while(s[i]!='\0')
        {
            if(s[i]>='a' && s[i]<='z')
            {
                res1+=s[i];
            }
            else if(!res1.empty())
            {
                res1.pop_back();
            }
            i++;
        }
        i = 0;
        while(t[i]!='\0')
        {
            if(t[i]>='a' && t[i]<='z')
            {
                res2+=t[i];
            }
            else if(!res2.empty())
            {
                res2.pop_back();
            }
            i++;
        }
        return res1==res2;
    }
};
// using stack
/*
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
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
        s = "";
        while(!s1.empty())
        {
            char c = s1.top();
            s1.pop();
            s+=c;
        }
        for(auto x : t)
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
        t = "";
        while(!s1.empty())
        {
            char c = s1.top();
            s1.pop();
            t+=c;
        }
        return s==t;
    }
};
*/