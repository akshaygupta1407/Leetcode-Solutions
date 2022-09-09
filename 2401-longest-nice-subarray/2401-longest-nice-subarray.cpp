class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mx = 0,an=0;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            int x = an&nums[j];
            if(x==0)
            {
                mx = max(mx,j-i+1);
                an|=nums[j];
                j++;
            }
            else
            {
                an^=nums[i];
                i++;
            }
        }
        return mx;
    }
};