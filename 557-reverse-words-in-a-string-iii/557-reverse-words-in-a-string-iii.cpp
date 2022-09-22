class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.length();
        string curr = "";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                res = ' ' + curr + res;
                curr = "";
            }
            else
            {
                curr+=s[i];
            }
        }
        res = curr + res;
        reverse(res.begin(),res.end());
        return res;
    }
};