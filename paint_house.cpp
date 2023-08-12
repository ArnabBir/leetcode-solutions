// Link : https://leetcode.com/problems/paint-house

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int mincost = INT_MAX;
                for (int k = 0; k < 3; ++k) {
                    if (j == k) {
                        continue;
                    }
                    mincost = min(mincost, costs[i][j] + costs[i-1][k]);
                }
                costs[i][j] = mincost;
            }
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};