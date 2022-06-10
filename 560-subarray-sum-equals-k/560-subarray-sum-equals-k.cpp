class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        int cumsum=0,count=0;
        mpp[0]++;
        for(int i=0;i<n;i++)
        {
            cumsum+=nums[i];
            count+=mpp[cumsum-k];
            mpp[cumsum]++;
        }
        return count;
    }
};