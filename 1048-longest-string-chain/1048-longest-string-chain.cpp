class Solution {
public:
    static bool cmp(const string &s1,const string &s2)
    {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>dp;
        sort(words.begin(),words.end(),cmp);
        int mx = 0;
        for(auto x : words)
        {
            for(int i=0;i<x.length();i++)
            {
                string sub = x.substr(0,i) + x.substr(i+1);
                if(dp.find(sub)==dp.end())
                {
                    dp[x] = max(dp[x],1);
                }
                else
                {
                    dp[x] = max(dp[x],dp[sub]+1);
                }
            }
            mx = max(mx,dp[x]);
        }
        return mx;
    }
};