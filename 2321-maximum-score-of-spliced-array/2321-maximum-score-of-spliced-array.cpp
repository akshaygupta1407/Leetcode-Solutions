class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
        for(auto x : nums1) sum1+=x;
        for(auto x : nums2) sum2+=x;
        int ans = max(sum1,sum2);
        int f=0,s=0,mx1=0,mx2=0;
        for(int i=0;i<nums1.size();i++)
        {
            f+=(nums2[i]-nums1[i]);
            s+=(nums1[i]-nums2[i]);
            if(f<0) f=0;
            if(s<0) s=0;
            mx1 = max(mx1,f);
            mx2 = max(mx2,s);
        }
        ans = max(ans,sum1+mx1);
        ans = max(ans,sum2+mx2);
        return ans;
    }
};