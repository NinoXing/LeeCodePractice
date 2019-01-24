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
	static bool compare(Interval &a, Interval &b){
		return a.start<b.start;
	}

    vector<Interval> merge(vector<Interval>& intervals) {
    	sort(intervals.begin(),intervals.end(),compare);
    	vector<Interval> res{intervals[0]};
    	for(int i=1; i<intervals.size(); i++){
    		if(intervals[i].start > res.back().end){
    			res.push_back(intervals[i]);
    		}
    		else{
    			res.back().end = max(res.back().end, intervals[i].end);
    		}
    	}
    	return res;
        
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> res;
    	int n=intervals.size();
    	int cur = 0;
    	while(cur<n && intervals[cur].end<newInterval.start){
    		res.push_back(intervals[cur]);
    		cur++;
    	}
    	while(cur<n && intervals[cur].start<=newInterval.end){
    		newInterval.start = min(intervals[cur].start, newInterval.start);
    		newInterval.end = max(intervals[cur].end,newInterval.end);
    		cur++;
    	}
    	res.push_back(newInterval);
    	while(cur<n){
    		res.push_back(intervals[cur++]);
    	}
    	return res;
        
    }
};