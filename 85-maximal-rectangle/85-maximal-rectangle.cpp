class Solution {
public:
    int histo(vector<int>&heights,int n)
      {
          stack<int>st;
          int mxArea = 0;
          for(int i=0;i<=n;i++)
          {
              int currHeight = i==n ? 0 : heights[i];
              while(!st.empty() && currHeight < heights[st.top()])
              {
                  int tp = st.top();
                  st.pop();
                  int width = st.empty() ? i : i-st.top()-1;
                  int area = heights[tp]*width;
                  mxArea = max(mxArea,area);
              }
              st.push(i);
          }
          return mxArea;
      }
    int maximalRectangle(vector<vector<char>>& M) {
        int n = M.size(), m = M[0].size();
        int res = 0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]=='1')
                v[j]+=1;
                else
                v[j] = 0;
            }
            res = max(res,histo(v,m));
        }
        return res;
    }
};