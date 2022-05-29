class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>mask(n);   
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(auto x : words[i])
            {
               mask[i] = mask[i] | 1 << (x - 'a'); 
            }
            for(int j=0;j<i;j++)
            {
                int a = mask[i];
                int b = mask[j];
                if((a&b)==0)
                {
                    int l = words[i].length() * words[j].length();
                    ans = max(ans,l);
                }
            }
        }
        return ans;
    }
};
// "abcw"
//     a = 1
//     b = 10
//     c = 100
//     w = 00010000000000000
//     ab 11
//     00010000000000000000000111
// 1 << 1          10
// 1<<2            100000