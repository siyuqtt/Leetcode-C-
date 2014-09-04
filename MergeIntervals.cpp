/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval > out;
        if(intervals.size() == 0) return out;
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b){ return a.start < b.start;});
        out.push_back( intervals[0] );
        for(int i = 1 ; i < intervals.size() ; i++){
            if(out.back().end >= intervals[i].start){
                if( out.back().end > intervals[i].end) continue;
                else{
                    out.back().end = intervals[i].end;
                }
            }else{
                out.push_back(intervals[i]);
            }
        }
        return out;
    }
};
