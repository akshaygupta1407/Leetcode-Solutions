class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mod = 1e9+7;
        long long mxL=0,mxH=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        mxH = max(mxH,(long long) horizontalCuts[0]);
        int n = horizontalCuts.size(), m = verticalCuts.size();
        for(int i=1;i<n;i++)
        {
            mxH = max(mxH,(long long)horizontalCuts[i]-horizontalCuts[i-1]);
        }
        mxH = max(mxH,(long long)h - horizontalCuts[n-1]);
        
        mxL = max(mxL,(long long)verticalCuts[0]);
        for(int i=1;i<m;i++)
        {
            mxL = max(mxL,(long long)verticalCuts[i]-verticalCuts[i-1]);
        }
        mxL = max(mxL,(long long)w - verticalCuts[m-1]);
        long long ans = (mxL*mxH)%mod;
        return (int)ans;
    }
};