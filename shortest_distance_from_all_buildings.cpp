class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};

    bool inside(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int> > buildings_pos;
        vector<pair<int,int> > empty_pos;
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        vector<vector<int> > vcount(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    buildings_pos.push_back({i,j});
                } else if (grid[i][j] == 0) {
                    empty_pos.push_back({i, j});
                }
            }
        }
        for (pair<int,int> p : buildings_pos) {
            vector<vector<bool> > visited(n, vector<bool>(m, false));
            visited[p.first][p.second] = true;
            queue<pair<int, pair<int, int> > > q;
            q.push({0, p});
            while (!q.empty()) {
                int d = q.front().first;
                int ux = q.front().second.first;
                int uy = q.front().second.second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int vx = ux + dx[i];
                    int vy = uy + dy[i];
                    if (!inside(vx, vy, n, m)
                        || visited[vx][vy]
                        || grid[vx][vy] != 0) {
                        continue;
                    }
                    ++vcount[vx][vy];
                    visited[vx][vy] = true;
                    q.push({d+1, {vx, vy}});
                    if (dist[vx][vy] == INT_MAX) {
                        dist[vx][vy] = 0;
                    }
                    dist[vx][vy] += d+1;
                }
            }
        }
        int ans = INT_MAX;
        for (pair<int,int> ep : empty_pos) {
            int x = ep.first;
            int y = ep.second;
            if (vcount[x][y] != buildings_pos.size()) {
                continue;
            }
            ans = min(ans, dist[ep.first][ep.second]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
