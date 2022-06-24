class Solution {
public:
    vector<vector<string>>res;
    bool isPalindrome(string s,int lo,int hi)
    {
        while(lo<hi)
        {
            if(s[lo++]!=s[hi--])    return false;
        }
        return true;
    }
    void helper(string s,int start,vector<string>&curr)
    {
        if(start==s.length()){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<s.length();i++)
        {
            if(isPalindrome(s,start,i))
            {
                curr.push_back(s.substr(start,i-start+1));
                helper(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        helper(s,0,curr);
        return res;
    }
};