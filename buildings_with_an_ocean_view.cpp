// Link : https://leetcode.com/problems/buildings-with-an-ocean-view/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> sh;
        for (int i = n-1; i >= 0; --i) {
            if(sh.empty()) {
                sh.push_back(i);
                continue;
            }
            if (heights[i] > heights[sh.back()]) {
                sh.push_back(i);
            }
        }
        reverse(sh.begin(), sh.end());
        return sh;
    }
};
