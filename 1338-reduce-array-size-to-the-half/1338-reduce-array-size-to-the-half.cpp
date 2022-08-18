class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>pq;
        map<int,int>mpp;
        for(auto x : arr)
        {
            mpp[x]++;
        }
        for(auto x : mpp)
        {
            pq.push(x.second);
        }
        int n = arr.size()/2;
        int count=0;
        while(!pq.empty())
        {
            if(n<=0)    break;
            n-=pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};