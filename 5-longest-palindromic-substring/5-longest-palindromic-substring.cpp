class Solution {
public:
    string extendfrommiddle(string s, int i, int j)
    {
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        for(int i=0;i<n;i++)
        {
            string s1 = extendfrommiddle(s,i,i);
            string s2 = extendfrommiddle(s,i,i+1);
            if(s1.length() > res.length())    res = s1;
            if(s2.length() > res.length())    res = s2;
        }
        return res;
    }
};