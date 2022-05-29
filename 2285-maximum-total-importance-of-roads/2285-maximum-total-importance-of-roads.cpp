class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>count(n,0);
        for(auto x : roads)
        {
            count[x[0]]++;
            count[x[1]]++;
        }
        sort(count.begin(),count.end());
        long long res = 0;
        for(long long i=0;i<n;i++)
        {
            res+=(count[i]*(i+1));
        }
        return res;
    }
};