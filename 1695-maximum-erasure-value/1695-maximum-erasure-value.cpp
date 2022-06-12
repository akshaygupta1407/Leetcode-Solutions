class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum = 0;
        int i=0,j=0,mx=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                while(j<nums.size() && m[nums[i]]>1)
                {
                    sum-=nums[j];
                    m[nums[j]]--;
                    j++;
                }
            }
            mx = max(mx,sum);
        }
        return mx;
    }
};