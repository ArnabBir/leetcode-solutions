// Link : https://leetcode.com/problems/employee-free-time/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {

    static bool compare_intervals(Interval a, Interval b) {
        return a.start < b.start;
    }

public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> schedules;
        for (vector<Interval> intervals : schedule) {
            for (Interval interval : intervals) {
                schedules.push_back(interval);
            }
        }
        sort(schedules.begin(), schedules.end(), compare_intervals);
        vector<Interval> merged;
        merged.push_back(schedules[0]);
        for (int i = 1; i < schedules.size(); ++i) {
            Interval last = merged.back();
            Interval curr = schedules[i];
            if (last.end >= curr.start) {
                int end = max(last.end, curr.end);
                merged[merged.size()-1].end = end;
            } else {
                merged.push_back(curr);
            }
        }
        vector<Interval> gaps;
        for (int i = 0; i < merged.size()-1; ++i) {
            gaps.push_back({merged[i].end, merged[i+1].start});
        }
        return gaps;
    }
};