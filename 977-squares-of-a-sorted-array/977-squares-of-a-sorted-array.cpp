class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int s = 0, e = nums.size()-1;
        int k = e;
        while(s<=e)
        {
            if(abs(nums[s])< abs(nums[e]))
            {
                res[k--] = nums[e]*nums[e];
                e--;
            }
            else
            {
                res[k--] = nums[s]*nums[s];
                s++;
            }
        }
        return res;
    }
};