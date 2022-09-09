class Solution {
public:
    static bool cmp1(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])  return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp1);
        int n = p.size();
        int count = 0,mx=0;
        for(int i=n-1;i>=0;i--)
        {
            if(p[i][1]<mx)
            {
                count++;
            }
            mx = max(mx,p[i][1]);
        }
        return count;
    }
};