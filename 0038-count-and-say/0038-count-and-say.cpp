class Solution {
public:
    string countAndSay(int n) {
        if(n==0)    return "";
        string ans = "1";
        while(--n)
        {
            string curr = "";
            int count = 1;
            for(int i=0;i<ans.size();i++)
            {
                if((i+1 < ans.size()) && ans[i]==ans[i+1])
                {
                    count++;
                }
                else
                {
                    curr+=to_string(count) + ans[i];
                    count = 1;
                }
            }
            ans = curr;
        }
        return ans;
    }
};