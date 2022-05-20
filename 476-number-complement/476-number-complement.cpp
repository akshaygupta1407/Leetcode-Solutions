class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int j = num;
        while(j!=0)
        {
            j/=2;
            count++;
        }
        int ans = pow(2,count)-1;
        return ans^num;
    }
};
// 5 ->101
// 101 ^ 111 = 010 = 2