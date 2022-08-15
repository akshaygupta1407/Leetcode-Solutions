class Solution {
public:
    int check(char ch)
    {
        if(ch=='I')
        {
            return 1;
        }
        else if(ch=='V')
        {
            return 5;
        }
        else if(ch=='X')
        {
            return 10;
        }
        else if(ch=='L')
        {
            return 50;
        }
        else if(ch=='C')
        {
            return 100;
        }
        else if(ch=='D')
        {
            return 500;
        }
        return 1000;
    }
    int romanToInt(string s) {
        int number = 0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(check(s[i])>=check(s[i+1]))
            {
                number+=check(s[i]);
            }
            else
            {
                number-=check(s[i]);
            }
        }
        number+=check(s[s.length()-1]);
        return number;
    }
};