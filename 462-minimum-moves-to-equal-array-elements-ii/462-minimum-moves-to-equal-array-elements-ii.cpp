class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int no = nums[n/2];
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=abs(nums[i]-no);
        }
        return sum;
    }
};
// 1 2 9 10
// take 2
// 1 0 7 8
// take 9
// 8 7 0 1