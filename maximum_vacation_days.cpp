// Link : https://leetcode.com/problems/maximum-vacation-days

class Solution {
    int maxVacationDaysBacktracking(vector<vector<int>>& flights,
                                    vector<vector<int>>& days,
                                    int n, int k) {
        vector<vector<int>> dp(k, vector<int>(n, 0));
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (flights[0][i] == 0 && i != 0) {
                continue;
            }
            dp[0][i] = days[i][0];
            q.push(i);
        }
        for (int w = 1; w < k; ++w) {
            unordered_set<int> us;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                 for (int j = 0; j < n; ++j) {
                     if (flights[i][j] == 0 && i != j) {
                        continue;
                     }
                     dp[w][j] = max(dp[w][j], dp[w-1][i] + days[j][w]);
                     us.insert(j);
                 }
            }
            for (int x : us) {
                q.push(x);
            }
        }
        return *max_element(dp[k-1].begin(), dp[k-1].end());
    }
 
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        return maxVacationDaysBacktracking(flights, days, n, k);
    }
};
