class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int curr = 0;
            for(int j=i;j<n;j++)
            {
                curr = __gcd(curr,nums[j]);
                if(curr==k) count++;
                if(curr < k) break;
            }
        }
        return count;
    }
};