class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long n = chargeTimes.size();
        long long mx = 0;
        vector<long long> runningCost(n,0);
        runningCost[0] = runningCosts[0];
        for(long long i=1;i<n;i++)
        {
            runningCost[i]=runningCost[i-1]+ runningCosts[i];
        }
        deque<long long>dq;
        long long i=0,j=0;
        while(i<n)
        {
            if(dq.empty())
            {
                dq.push_back(chargeTimes[i]);
            }
            long long x = dq.front();
            long long y = (long long)(abs(i-j)+1)*(j==0 ? runningCost[i] : runningCost[i] - runningCost[j-1]);
            long long check = ((long long)x+(long long)y);;
            if(check <= budget)
            {
                mx = max(mx,abs(i-j+1));
                i++;
                if(i<n && (dq.back() < chargeTimes[i]))
                {
                    while(!dq.empty() && dq.back() < chargeTimes[i])
                    dq.pop_back();
                    
                    dq.push_back(chargeTimes[i]);
                }
                else if(i<n && (dq.back() >= chargeTimes[i]))
                {
                    dq.push_back(chargeTimes[i]);
                }
            }
            else
            {
                if(j<n && dq.front()==chargeTimes[j])
                {
                    dq.pop_front();
                }
                j++;
                if(i<j)
                {
                    i++;
                }
            }
        }
        return mx;
    }
};