// Link : https://leetcode.com/problems/line-reflection

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> um;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            um[y].insert(x);
        }
        double last_centroid = INT_MIN;
        for (auto it : um) {
            unordered_set<int> curr_elem = it.second;
            double curr_centroid_double = accumulate(curr_elem.begin(), curr_elem.end(), 0) / ((double)curr_elem.size());
            if (last_centroid != INT_MIN && last_centroid != curr_centroid_double) {
                return false;
            }
            int curr_centroid_int = (int) curr_centroid_double;
            if (curr_elem.size()%2 == 1 && curr_centroid_int != curr_centroid_double) {
                return false;
            }
            if (curr_elem.size()%2 == 1 && curr_elem.find(curr_centroid_int) == curr_elem.end()) {
                return false;
            }
            last_centroid = curr_centroid_double;
        }
        return true;
    }
};
