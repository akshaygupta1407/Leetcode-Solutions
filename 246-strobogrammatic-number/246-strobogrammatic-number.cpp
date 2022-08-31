class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char>mpp;
        mpp['0'] = '0', mpp['1'] = '1',mpp['6'] = '9', mpp['8'] = '8',mpp['9'] = '6';
        int i=0,l = num.length();
        int e = l-1;
        while(i<=e)
        {
            if(mpp.find(num[i])==mpp.end() || mpp.find(num[e])==mpp.end())    return false;
            if(mpp[num[i]]!=num[e]) return false;
            i++;e--;
            
        }
        return true;
    }
};
/*
1 1
5 5
6 9
8 8
9 6
0 0
*/