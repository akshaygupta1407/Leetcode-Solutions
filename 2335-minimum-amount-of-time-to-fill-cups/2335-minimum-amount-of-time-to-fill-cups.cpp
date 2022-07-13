class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(auto x : amount)
        {
            pq.push(x);
        }
        if(pq.top()==0) return 0;
        int cnt = 0;
        while(pq.top()!=0)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x--,y--;
            pq.push(x);
            pq.push(y);
            cnt++;
        }
        return cnt;
    }
};