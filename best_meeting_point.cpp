// Link : https://leetcode.com/problems/best-meeting-point

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};

    bool inside(int x, int y, int n, int m) {
        return (x >= 0) && (y >= 0) && (x < n) && (y < m);
    }
 
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        queue<pair<pair<int,int>, int>> q;
        q.push({{i,j},0});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        visited[i][j] = true;
        while (!q.empty()) {
            pair<int,int> point = q.front().first;
            int d = q.front().second;
            int x = point.first;
            int y = point.second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (!inside(x1, y1, n, m) || visited[x1][y1]) {
                    continue;
                }
                visited[x1][y1] = true;
                dp[x1][y1] += d+1;
                q.push({{x1,y1},d+1});
            }
        }
    }

public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> parents;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, dp, i, j);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = min(dp[i][j], ans);
            }
        }
        return ans;
    }
};
