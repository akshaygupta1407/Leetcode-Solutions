class Solution {
public:
    long long count = 0;
    void helper(vector<int>&v,int start,int mid,int end,int d)
    {
        int l = start, r = mid+1;
        while(l<=mid && r<=end)
        {
            if(v[l] <= (v[r] + d))
            {
                count+=(end-r+1);
                l++;
            }
            else
            {
                r++;
            }
        }
        sort(v.begin()+start,v.begin()+end+1);
        return;
    }
    void mergesort(vector<int>&v,int l,int e,int d)
    {
        if(l<e)
        {
            int mid = (l+e)/2;
            mergesort(v,l,mid,d);
            mergesort(v,mid+1,e,d);
            helper(v,l,mid,e,d);
        }
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int d) {
        count = 0;
        int n = nums1.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            v[i] = nums1[i] - nums2[i];
        }
        mergesort(v,0,n-1,d);
        return count;
    }
};