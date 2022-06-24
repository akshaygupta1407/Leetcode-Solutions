class Solution {
public:
    string shortestPalindrome(string s) {
        int l = s.length();
        int i = 0;
        for(int j=l-1;j>=0;j--)
        {
            if(s[i]==s[j])  i++;
        }
        if(i==l)    return s;
        string remaining = s.substr(i);
        reverse(remaining.begin(),remaining.end());
        return remaining + shortestPalindrome(s.substr(0,i)) + s.substr(i);
    }
};