class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0,e = n-1;
        int index1 = -1, index2 = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] < target)
            {
                s = mid+1;
            }
            else if(nums[mid]>target)
            {
                e = mid-1;
            }
            else if(nums[mid]==target)
            {
                index1 = mid;
                e = mid-1;
            }
        }
        s = 0,e = n-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] < target)
            {
                s = mid+1;
            }
            else if(nums[mid]>target)
            {
                e = mid-1;
            }
            else if(nums[mid]==target)
            {
                index2 = mid;
                s = mid+1;
            }
        }
        return {index1,index2};
    }
};

// 5 7 7 8 8 10
    
// 0 + 6 / 2 = 3 