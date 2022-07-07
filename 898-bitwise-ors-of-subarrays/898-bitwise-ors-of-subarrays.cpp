class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        if(arr.size()==0) return 0;
        set<int>ret,prev;
        ret.insert(arr[0]),prev.insert(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            set<int>curr;
            ret.insert(arr[i]);
            curr.insert(arr[i]);
            for(auto a : prev)
            {
                curr.insert(a|arr[i]);
                ret.insert(a|arr[i]);
            }
            prev = curr;
        }
        return ret.size();
    }
};