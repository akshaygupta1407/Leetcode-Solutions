class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n),right(n);
        int curr = 1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                left[i] = 0;
                curr = 1;
            }
            else
            {
                curr*=nums[i];
                left[i] = curr;
            }
        }
        curr = 1;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                right[i] = 0;
                curr = 1;
            }
            else
            {
                curr*=nums[i];
                right[i] = curr;
            }
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,max(left[i],right[i]));
        }
        return mx;
    }
};