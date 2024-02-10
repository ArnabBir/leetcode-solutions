// Link : https://leetcode.com/problems/number-of-distinct-islands-ii/

class Solution {
    int dx[4] = { 0, 0,-1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    bool inside(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    string to_insland_string(vector<vector<int> >& islands) {
        
        string all_islands = "";
        for (vector<int> island : islands) {
            all_islands += to_point_string(island[0], island[1]) + ":";
        }
        return all_islands;
    }

    string to_point_string(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }
 
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<string> islands;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                queue<pair<int,int> > q;
                q.push({i, j});
                grid[i][j] = 0;
                vector<vector<int> > points;
                while(!q.empty()) {
                    pair<int,int> curr = q.front();
                    q.pop();
                    int ux = curr.first;
                    int uy = curr.second;
                    points.push_back({ux, uy});
                    for (int i = 0; i < 4; ++i) {
                        int vx = ux + dx[i];
                        int vy = uy + dy[i];
                        if (!inside(vx, vy, n, m) || grid[vx][vy] == 0) {
                            continue;
                        }
                        grid[vx][vy] = 0;
                        q.push({vx, vy});
                    }
                }
                vector< vector<vector<int> > > pointss(8);
                for (vector<int> p : points) {
                    int x = p[0], y = p[1];
                    pointss[0].push_back({ x, y});
                    pointss[1].push_back({ x,-y});
                    pointss[2].push_back({-x, y});
                    pointss[3].push_back({-x,-y});
                    pointss[4].push_back({ y, x});
                    pointss[5].push_back({ y,-x});
                    pointss[6].push_back({-y, x});
                    pointss[7].push_back({-y,-x});
                }
                for (int i = 0; i < 8; ++i) {
                    sort(pointss[i].begin(), pointss[i].end());
                    vector<int> first = pointss[i][0];
                    for (int j = 0; j < (int)pointss[i].size(); ++j) {
                        pointss[i][j][0] -= first[0];
                        pointss[i][j][1] -= first[1];
                    }
                }
                sort(pointss.begin(), pointss.end());
                islands.insert(to_insland_string(pointss[0]));
            }
        }
        return islands.size();
    }
};
