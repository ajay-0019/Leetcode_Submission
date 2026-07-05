class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
           return a[1] < b[1];
        });
        int remove=0;
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]<intervals[i-1][1]){
                remove++;
                intervals[i][1]=intervals[i-1][1];
                i++;
            }else{
                i++;
            }
        }
        return remove;
    }
};