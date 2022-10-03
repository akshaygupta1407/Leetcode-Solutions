class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mx=0,currtime=0;
        int n = colors.length();
        for(int i=0;i<n;i++)
        {
            if(i>0 && colors[i]!=colors[i-1])   currtime = 0;
            mx+=min(currtime,neededTime[i]);
            currtime = max(currtime,neededTime[i]);
        }
        return mx;
    }
};