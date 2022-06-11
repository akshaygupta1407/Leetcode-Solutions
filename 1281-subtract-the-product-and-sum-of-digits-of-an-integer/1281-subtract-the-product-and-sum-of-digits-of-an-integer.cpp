class Solution {
public:
    int subtractProductAndSum(int n) {
        string res = to_string(n);
        int sum=0,prod=1;
        for(auto x : res)
        {
            sum+= (x-'0');
            prod*=(x-'0');
        }
        return prod - sum;
    }
};