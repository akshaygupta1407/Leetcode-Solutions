class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        priority_queue<pair<int,int>>pq;    //maxheap meaning in descending order
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto x : m)
        {
            pq.push({x.second,x.first});
        }
        vector<int>res;
        while(k--)
        {
            int tp = pq.top().second;
            pq.pop();
            res.push_back(tp);
        }
        return res;
    }
};