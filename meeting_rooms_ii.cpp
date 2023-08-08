// Link : https://leetcode.com/problems/meeting-rooms-ii
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> p;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            p.push_back({intervals[i][0], 1});
            p.push_back({intervals[i][1], -1});
        }
        sort(p.begin(), p.end());
        int count = 0;
        int maxcount = 0;
        for (int i = 0; i < 2*n; ++i) {
            count += p[i].second;
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};