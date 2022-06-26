class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n  = arr.size();
        if(k==n)
        {
            int sum = 0;
            for(auto x : arr)
                sum+=x;
            return sum;
        }
        int l = 0;
        int sum = 0,mx = 0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
            l = i;
        }
        mx = max(mx,sum);
        for(int i=0;i<k;i++)
        {
            sum+=arr[n-i-1];
            sum-=arr[l];
            l--;
            mx = max(mx,sum);
        }
        return mx;
    }
};