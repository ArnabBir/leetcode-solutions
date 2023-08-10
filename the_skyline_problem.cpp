// Link : https://leetcode.com/problems/the-skyline-problem/submissions

class Height {
    public:
        int h;
        bool start;
        Height(int h, bool start) {
            this->h = h;
            this->start = start;
        }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        ms.insert(0);
        int n = buildings.size();
        vector<vector<int>> result;
        map<int, vector<Height*>> points;
        for (int i = 0; i < n; ++i) {
            points[buildings[i][0]].push_back(new Height(buildings[i][2], true));
            points[buildings[i][1]].push_back(new Height(buildings[i][2], false));
        }
        int last = 0;
        for (auto point : points) {
            for (Height * height : point.second) {
                int h = height->h;
                bool start = height->start;
                if (start) {
                    ms.insert(h);
                } else {
                    ms.erase(ms.lower_bound(h));
                }
            }
            int x = point.first;
            int curr = *ms.rbegin();
            result.push_back({x, curr});
        }
        vector<vector<int>> compactresult;
        for (int i = 0; i < result.size(); ++i) {
            if (i == 0 || compactresult.back()[1] != result[i][1]) {
                compactresult.push_back(result[i]);
            }
        }
        return compactresult;
    }
};
