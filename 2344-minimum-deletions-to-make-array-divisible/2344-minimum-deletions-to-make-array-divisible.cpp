class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            gcd = __gcd(gcd,numsDivide[i]);
        }
        cout<<gcd<<endl;
        sort(nums.begin(),nums.end());
        int ans = -1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(gcd%nums[i]==0)
            {
                ans = count;
                break;
            }
            else
            {
                count++;
            }
        }
        return ans;
    }
};