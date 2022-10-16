class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int l = strs.size();
        int i=0,j=0;
        string res = "";
        while(i<strs[0].length() && j<strs[l-1].length())
        {
            if(strs[0][i]==strs[l-1][j])
            {
                res+=strs[0][i];
                i++;
                j++;
            }
            else break;
        }
        return res;
    }
};