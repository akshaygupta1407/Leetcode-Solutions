class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
         int len = intervals.size();
        if (len <= 1) {
            return true;
        }
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]>intervals[i+1][0])   return false;
        }
        return true;
    }
};