class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,curr=0,start=0,diff=0;
        for(int i=0;i<gas.size();i++)
        {
            diff = gas[i]-cost[i];
            total+=diff;
            curr+=diff;
            if(curr<0)
            {
                start = i+1;
                curr = 0;
            }
        }
        if(total>=0)
        {
            return start;
        }
        return -1;
    }
};
// [1,2,3,4,5][1,2,3,4,5]
// [3,4,5,1,2]