class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if( intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        bool mergeS = false;
        auto Sit = intervals.begin();
        while(Sit != intervals.end()){
            if( Sit->end >= newInterval.start){ // start point 
                break;
            }
            Sit++;
        }
        auto Eit = next(intervals.begin(), distance(intervals.begin(), Sit));
        while(Eit != intervals.end()){
            if( Eit->start > newInterval.end) break;// end point
            Eit++;
        }
        if(Sit == Eit) intervals.insert(Sit, newInterval);
        else{
            newInterval.start = min(newInterval.start, Sit->start);
            newInterval.end = max(newInterval.end, prev(Eit)->end);
            intervals.erase(Sit, Eit);
            intervals.insert(Sit, newInterval);
        }
       return intervals;
    }
};
