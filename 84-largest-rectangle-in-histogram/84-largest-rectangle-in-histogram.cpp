class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int mxArea = 0;
        for(int i=0;i<=n;i++)
        {
            int currHeight = i==n ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()])
            {
                int tp = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = heights[tp]*width;
                mxArea = max(mxArea,area);
            }
            st.push(i);
        }
        return mxArea;
    }
};