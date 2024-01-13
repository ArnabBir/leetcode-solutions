// Link : https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};

    bool inside(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    string to_point_string(int x, int y) {
        return to_string(x) + "-" + to_string(y);
    }

    string to_insland_string(vector<string>& islands) {
        string all_islands = "";
        for (string island : islands) {
            all_islands += island + ":";
        }
        return all_islands;
    }

    string dfs(vector<vector<int> >& grid, int x, int y, int n, int m) {
        stack<pair<int,int> > s;
        vector<string> islands;
        s.push({x, y});
        if (grid[x][y] == 0) {
            return "";
        }
        islands.push_back(to_point_string(0, 0));
        grid[x][y] = 0;
        while (!s.empty()) {
            pair<int,int> point = s.top();
            s.pop();
            int ux = point.first;
            int uy = point.second;
            for (int i = 0; i < 4; ++i) {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if (!inside(vx, vy, n, m) || grid[vx][vy] == 0) {
                    continue;
                }
                s.push({vx, vy});
                islands.push_back(to_point_string(vx-x, vy-y));
                grid[vx][vy] = 0;
            }
        }
        return to_insland_string(islands);
    } 

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<string> islands;
        stack<pair<int,int> > s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string key = dfs(grid, i, j, n, m);
                if (key != "") {
                    islands.insert(key);
                }
            }
        }
        return islands.size();
    }
};