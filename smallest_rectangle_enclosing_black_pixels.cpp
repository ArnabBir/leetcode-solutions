// Link : https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0,-1, 1};
    
    bool inside(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        queue<pair<int,int>> q;
        q.push({x,y});
        image[x][y] = '0';
        int n = image.size();
        int m = image[0].size();
        int minx = x, miny = y, maxx = x, maxy = y;
        while (!q.empty()) {
            pair<int,int> point = q.front();
            q.pop();
            x = point.first;
            y = point.second;
            for (int i = 0; i < 4; ++i) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (!inside(x1, y1, n, m) || image[x1][y1] == '0') {
                    continue;
                }
                maxx = max(x1, maxx);
                maxy = max(y1, maxy);
                minx = min(x1, minx);
                miny = min(y1, miny);
                image[x1][y1] = '0';
                q.push({x1, y1});
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};