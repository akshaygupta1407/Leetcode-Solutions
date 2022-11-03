class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mpp;
        int ans = 0;
        for(auto x : words)
        {
            string y = "";
            y+=x[1];
            y+=x[0];
            if(mpp[y]>0)
            {
                ans+=4;
                mpp[y]--;
            }
            else
            {
                mpp[x]++;
            }
        }
        for(auto x : mpp)
        {
            if(x.second>0 && x.first[0]==x.first[1])
            {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};