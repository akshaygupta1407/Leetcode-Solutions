class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0,neg = 0,res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                pos = 0;
                neg = 0;
            }
            else if(nums[i]>0)
            {
                pos++;
                if(neg!=0)  neg++;
                res = max(res,pos);
            }
            else
            {
                swap(pos,neg);
                neg++;
                if(pos!=0)
                    pos++;
                res = max(res,pos);
            }
        }
        return res;
    }
};
// 1 -2 -3 4
// pos = 2
// neg = 1
// res = 1