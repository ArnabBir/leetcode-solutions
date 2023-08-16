// Link : https://leetcode.com/problems/the-maze

class Solution {
    bool in_maze(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = { 0, 0,-1, 1};
        stack<pair<int, vector<int>>> s;
        vector<vector<bool>> visited(n, vector<bool>(m));
        s.push({0, start});
        while (!s.empty()) {
            vector<int> curr = s.top().second;
            int d = s.top().first;
            s.pop();
            int x = curr[0];
            int y = curr[1];
            if (visited[x][y]) {
                continue;
            }
            visited[x][y] = true;
            if (x == destination[0] && y == destination[1]) {
                return true;
            }
            for (int i = 0; i < 4; ++i) {
                int x1 = x;
                int y1 = y;
                while (in_maze(x1 + dx[i] , y1 + dy[i], n, m) && maze[x1 + dx[i]][y1 + dy[i]] == 0) {
                    x1 += dx[i];
                    y1 += dy[i];
                }
                s.push({i, {x1, y1}});
            }
        }
        return false;
    }
};