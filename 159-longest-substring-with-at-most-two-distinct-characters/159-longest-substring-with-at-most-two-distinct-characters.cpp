class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if(n<3) return n;
        map<char,int>mpp;
        int l=0,r=0;
        int mxlen = 2;
        while(r<n)
        {
            mpp[s[r]] = r;
            r++;
            if(mpp.size()==3)
            {
                int del_idx = INT_MAX;
                for(auto element:mpp)
                {
                    del_idx = min(del_idx,element.second);
                }
                mpp.erase(s[del_idx]);
                l = del_idx+1;
            }
            mxlen = max(mxlen,r-l);
        }
        return mxlen;
    }
};