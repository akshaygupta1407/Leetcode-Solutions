class Solution {
public:
    int longestSubsequence(string s, int k) {
    int n = s.size(), res = 0, sum = 0;
    for(int i=n-1; i>=0; i--){
        int num = s[i]-'0';
        //if zero, include it always no matter what
        if(num == 0)
            res++;
        else{
            //if one, we need to reduce the LSB,
            //same time make it longest and under K
            int j = n-i-1;
            // cout<<j<<endl;
            if(sum + pow(2, j) <= k){
                sum += pow(2, j);
                cout<<pow(2,j)<<endl;
                // cout<<sum<<endl;
                res++;
            }
        }
    }
    return res;
}
};