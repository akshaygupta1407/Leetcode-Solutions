class Solution {
public:
    //after sorting envelopes according to its height, we will find longest increasing subsequence in the width to find the envelopes
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int dfs(vector<vector<int>>& envelopes,int n)
    {
        vector<int>lis;
        for(int i=0;i<n;i++)
        {
            int ele = envelopes[i][1];
            int index = lower_bound(lis.begin(),lis.end(),ele) - lis.begin();
            if(index>=lis.size())   lis.push_back(ele);
            else lis[index] = ele;
        }
        return lis.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==1)
            return 1;
        // sorting by height & if we encounter same height
        // sort by descending order of width
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        return dfs(envelopes,n);
    }
};
