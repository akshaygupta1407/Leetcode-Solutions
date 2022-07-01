class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]<9)
        {
            digits[n-1] += 1;
            return digits;
        }
        int i = n-1;
        while(i>=0 && (digits[i]+1==10))
        {
            digits[i] = 0;
            i--;
        }
        if(i==-1)
        {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());  
        }
        else
        {
            digits[i]++;
        }
        return digits;
    }
};