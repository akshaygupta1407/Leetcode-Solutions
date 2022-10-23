class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // sum[1 to n] + duplicate - missing = sum[array]
        int n = nums.size();
        int sNums = 0, sOneToN = 0;
        sOneToN = (n*(n+1))/2;
        for(auto x : nums)
        {
            sNums+=x;
        }
        int duplicate = -1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int curr = abs(nums[i]);
            if(nums[curr-1]>0)
            {
                nums[curr-1]*=-1;
            }
            else
            {
                duplicate = curr;
                ans.push_back(duplicate);
                break;
            }
        }
        int missing = sOneToN + duplicate - sNums;
        ans.push_back(missing);
        return ans;
    }
};