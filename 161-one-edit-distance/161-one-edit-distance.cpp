class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n=s.length(),m=t.length();
        if(n>m) return isOneEditDistance(t,s);
        if(m-n>1)   return false;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(n==m)
                {
                    return s.substr(i+1)==t.substr(i+1);
                }
                else
                {
                    return s.substr(i)==t.substr(i+1);
                }
            }
        }
        return m-n==1;
    }
};