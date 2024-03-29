class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>s1,s2;
        int n = arr.size();
        long left[n], right[n];
        for(int i=0;i<n;i++)
        {
            int cnt = 1;
            while(!s1.empty() && s1.top().first > arr[i])
            {
                cnt+=s1.top().second;
                s1.pop();
            }
            s1.push({arr[i],cnt});
            left[i] = cnt;
        }
        for(int i=n-1;i>=0;i--)
        {
            int cnt = 1;
            while(!s2.empty() && s2.top().first >= arr[i])
            {
                cnt+=s2.top().second;
                s2.pop();
            }
            s2.push({arr[i],cnt});
            right[i] = cnt;
        }
        long res = 0;
        constexpr int mod = 1e9+7;
        for(int i=0;i<n;i++)
        {
            res = (res + arr[i]*left[i]*right[i])%mod;
        }
        return res;
    }
};