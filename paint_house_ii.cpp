// Link : https://leetcode.com/problems/paint-house-ii

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                int temp = INT_MAX;
                for (int l = 0; l < k; ++l) {
                    if (l != j) {
                        temp = min(temp, costs[i][j] + costs[i-1][l]);
                    }
                }
                costs[i][j] = temp;
            }
        }

        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};