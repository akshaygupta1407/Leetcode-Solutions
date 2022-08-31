class Solution {
public:
    void reverseWords(vector<char>& s) {
        int l = s.size();
        string res = "",curr="";
        for(int i=0;i<l;i++)
        {
            if(s[i]==' ')
            {
                res = curr + ' ' + res;
                curr = "";
            }
            else
            { 
                curr+=s[i];
            }
        }
        res = curr + ' ' + res;
        for(int i=0;i<l;i++)
        {
            s[i] = res[i];
        }
    }
};
/*
s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]

*/