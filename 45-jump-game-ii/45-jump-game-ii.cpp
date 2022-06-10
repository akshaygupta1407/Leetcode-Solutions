class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,currF=0,currE=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            currF = max(currF,nums[i]+i);
            if(currE==i)
            {
                currE = currF;
                jump++;
            }
        }
        return jump;
    }
};