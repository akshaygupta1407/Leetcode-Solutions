class Solution {
public:
    int cnt = 0;
    void palindrome(string s,int l,int e)
    {
        while(l>=0 && e<=s.length() && s[l]==s[e])
        {
            cnt++;
            l--;
            e++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++)
        {
            palindrome(s,i,i);
            palindrome(s,i,i+1);
        }
        return cnt;
    }
};
