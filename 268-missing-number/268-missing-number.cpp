class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalsum = n*(n+1)/2;
        for(int x : nums)
            totalsum-=x;
        return totalsum;
    }
};