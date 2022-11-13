class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, e = n-1;
        unordered_set<float>set;
        while(l<e)
        {
            float d = (nums[l] + nums[e])/2.0;
            l++;
            e--;
            set.insert(d);
        }
        return set.size();
    }
};