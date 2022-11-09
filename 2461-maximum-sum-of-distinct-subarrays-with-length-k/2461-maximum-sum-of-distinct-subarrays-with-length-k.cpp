class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();
        int i = 0;
        long long sum=0,mx = 0;
        int j = 0;
        while(i<n)
        {
            if(st.size()==k)
            {
                mx = max(mx,sum);
                sum -= nums[j];
                st.erase(nums[j++]);
            }
            else
            {
                if(!st.count(nums[i]))
                {
                    st.insert(nums[i]);
                    sum+=nums[i];
                    i++;
                }
                else
                {
                    sum -= nums[j];
                    st.erase(nums[j++]);
                }
            }
        }
        if(st.size()==k)
        {
            mx = max(mx,sum);
        }
        return mx;
    }
};