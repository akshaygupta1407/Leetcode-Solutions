class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = 0,curr = 0;
        for(int i=0;i<values.size();i++)
        {
            mx = max(mx,curr + values[i]-i);
            curr = max(curr,values[i]+i);
        }
        return mx;
    }
};