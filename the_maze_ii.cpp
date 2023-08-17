// Link : https://leetcode.com/problems/the-maze-ii

class Solution {
    bool in_maze(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = { 0, 0,-1, 1};
        stack<pair<int, vector<int>>> s;
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[start[0]][start[1]] = 0;
        int mind = INT_MAX;
        s.push({0, start});
        while (!s.empty()) {
            vector<int> curr = s.top().second;
            int d = s.top().first;
            s.pop();
            int x = curr[0];
            int y = curr[1];

            if (x == destination[0] && y == destination[1]) {
                mind = min(mind, d);
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int x1 = x;
                int y1 = y;
                int count = 0;
                while (in_maze(x1 + dx[i] , y1 + dy[i], n, m) && maze[x1 + dx[i]][y1 + dy[i]] == 0) {
                    x1 += dx[i];
                    y1 += dy[i];
                    ++count;
                }
                if (distance[x][y] + count < distance[x1][y1]) {
                    distance[x1][y1] = distance[x][y] + count;
                    s.push({d + count, {x1, y1}});
                }
            }
        }
        return mind == INT_MAX ? -1 : mind;
    }
};
