class Solution {
public:
    int dp[101][101][601];
    int helper(vector<string>& strs, int zero, int one, int index)
    {
        if(index>=strs.size() || (zero==0 && one==0))
            return 0;
        
        int countzero = 0,countone = 0;
        
        if(dp[zero][one][index]>0)
            return dp[zero][one][index];
        
        for(auto x : strs[index])
        {
            if(x=='0')  countzero++;
            else countone++;
        }
        
        int consider = (zero>=countzero && one>=countone) ? 1 + helper(strs,zero-countzero,one-countone,index+1) : 0;
        
        int skip = helper(strs,zero,one,index+1);
        
        return dp[zero][one][index] = max(consider,skip);
            
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs,m,n,0);
    }
};