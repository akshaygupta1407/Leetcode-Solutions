class Solution {
public:
    int operation(string &word1, string &word2,int i,int j,int l1,int l2, vector<vector<int>>&dp)
    {
        if(i==l1 && j==l2)
            return 0;
        if(i==l1 || j==l2)
        {
            return max(l1-i,l2-j);
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
        {
            return dp[i][j] = operation(word1,word2,i+1,j+1,l1,l2,dp);
        }
        return dp[i][j] = 1 + min(operation(word1,word2,i,j+1,l1,l2,dp),operation(word1,word2,i+1,j,l1,l2,dp));
        
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length(),l2 = word2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return operation(word1,word2,0,0,l1,l2,dp);
    }
};