class Solution {
public:
    double average(vector<int>& salary) {
       long long mx = INT_MIN,mn = INT_MAX,total = 0;
        for(int i=0;i<salary.size();i++)
        {
            mx = max(mx,(long long)salary[i]);
            mn = min(mn,(long long)salary[i]);
            total+=salary[i];
        }
        total = total - mn - mx;
        double res = (total*1.0)/(salary.size()-2);
        return res;
    }
};