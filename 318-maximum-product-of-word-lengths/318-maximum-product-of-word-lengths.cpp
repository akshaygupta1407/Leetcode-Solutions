class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>mask(n);
        int len = 0;
        for(int i=0;i<n;i++)
        {
            for(auto x : words[i])
            {
                mask[i] = mask[i] | 1<<(x-'a');
            }
            for(int j=0;j<i;j++)
            {
                if((mask[i]&mask[j])==0)
                {
                    int l1 = words[i].length();
                    int l2 = words[j].length();
                    int l = l1*l2;
                    len = max(len,l);
                }
            }
        }
        return len;
    }
};