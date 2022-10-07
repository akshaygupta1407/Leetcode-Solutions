class Solution {
public:
    int ans = 0;
    int longestDecomposition(string text) {
        int l = text.length();
        int i=0,j=l-1;
        string res = "";
        while(i<l)
        {
            res+=text[i];
            if(res==text.substr(j,res.length()))
            {
                // cout<<res<<endl;
                ans++;
                res = "";
            }
            i++;
            j--;
        }
        return ans;
    }
};
// ghiabcdefhelloadamhelloabcdefghi