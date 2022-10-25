class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end()); 
        vector<int>e1,e2,o1,o2;
        for(auto x : nums)
        {
            if(x%2==0) e1.push_back(x);
            else o1.push_back(x);
        }
        for(auto x : target)
        {
            if(x%2==0) e2.push_back(x);
            else o2.push_back(x);
        }
        long long ans = 0;
        for(int i=0;i<e1.size();i++)
        {
            ans+=abs(e1[i]-e2[i]);
        }
        for(int i=0;i<o1.size();i++)
        {
            ans+=abs(o1[i]-o2[i]);
        }
        return ans/4;
    }
};