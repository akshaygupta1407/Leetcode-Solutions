class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<30;i++)
        {
            int no = pow(2,i);
            string sno = to_string(no);
            sort(sno.begin(),sno.end());
            if(sno==s)  return true;
        }
        return false;
    }
};