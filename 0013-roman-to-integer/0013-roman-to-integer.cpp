class Solution {
public:
    int roman(char ch)
    {
        if(ch=='I') return 1;
        if(ch=='V') return 5;
        if(ch=='X') return 10;
        if(ch=='L') return 50;
        if(ch=='C') return 100;
        if(ch=='D') return 500;
        return 1000;
    }
    int romanToInt(string s) {
        int sum = 0;
        int l = s.length();
        for(int i=0;i<l-1;i++)
        {
            if(roman(s[i])>=roman(s[i+1]))
            {
                sum+=roman(s[i]);
            }
            else
            {
                sum-=roman(s[i]);
            }
        }
        sum+=roman(s[l-1]);
        return sum;
    }
};