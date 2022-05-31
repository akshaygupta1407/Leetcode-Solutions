class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>set;
        if(k>s.length())return false;
        for(int i=0;i<s.length()-k+1;i++)
        {
            string p = s.substr(i,k);
            set.insert(p);
        }
        return set.size()==(pow(2,k));
    }
};
// // 00
// //     01
// //     10
// //     11
// //     100
// //     101
// //     110
// //     111
// //     1000
// //     1001
// //     1010
// //     1011
// //     1100
// //     1101
// //     1110
// //     1111
// 10000n = 1
//     n = 1   2 -> 2^1
//     n=2   4->2^2
//     n=3