class Solution {
public:
    string breakPalindrome(string pal) {
        int l = pal.length();
        if(l==1)    return "";
        int n = l/2;
        for(int i=0;i<n;i++)
        {
            if(pal[i]!='a')
            {
                pal[i] = 'a';
                break;
            }
            else if(i==n-1)
            {
                pal[l-1] = 'b';
            }
        }
        return pal;
    }
};