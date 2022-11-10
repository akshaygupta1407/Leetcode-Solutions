class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if(n==1) 
        {
            return costs[0];
        }
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        int i=0,j=n-1,count=0;
        long long sum = 0;
        while(i<j && count<candidates)
        {
            count++;
            pq1.push(costs[i++]);
            pq2.push(costs[j--]);
        }
        i--;
        j++;
        while(k--)
        {
            if(pq1.size() && pq2.size())
            {
                if(pq1.top() > pq2.top())
                {
                    sum+=pq2.top();
                    pq2.pop();
                    if((j-i)>=2)
                    {
                        j--;
                        pq2.push(costs[j]);
                    }
                }
                else
                {
                    sum+=pq1.top();
                    pq1.pop();
                    if((j-i)>=2)
                    {
                        i++;
                        pq1.push(costs[i]);
                    }
                }
            }
            else
            {
                if(pq1.size())
                {
                    sum+=pq1.top();
                    pq1.pop();
                }
                else if(pq2.size())
                {
                    sum+=pq2.top();
                    pq2.pop();
                }
            }
        }
        return sum;
    }
};