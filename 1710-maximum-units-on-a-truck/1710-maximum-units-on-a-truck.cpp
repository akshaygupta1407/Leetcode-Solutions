class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0;
        int i = 0;
        while(truckSize>0 && i<n)
        {
            if(truckSize >= boxTypes[i][0])
            {
                truckSize -= boxTypes[i][0];
                ans+= boxTypes[i][0]*boxTypes[i][1];
            }
            else
            {
                ans+=truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
};