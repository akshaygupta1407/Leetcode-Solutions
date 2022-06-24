class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long sum = 0;
        for(int x : target)
        {
            pq.push(x);
            sum+=x;
        }
        while(pq.top()!=1)
        {
            int mx = pq.top();
            pq.pop();
            long diff = sum - mx;
            if(mx==1 || diff == 1)  return true;
            if(diff>mx || diff==0 || mx%diff==0)    return false;
            mx%=diff;
            sum = diff + mx;
            pq.push(mx);
            
        }
        return true;
    }
};