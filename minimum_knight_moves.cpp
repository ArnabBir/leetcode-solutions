// Link : https://leetcode.com/problems/minimum-knight-moves/

class Solution {
    int dx[8] = {1,2, 2, 1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1, 1, 2};
    
    string p_to_s(int x, int y) {
        return to_string(x) + ":" + to_string(y);
    }

public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        queue<pair<pair<int,int>, int> > sq, tq;
        unordered_map<string, int> sd, td;
        sq.push({{0,0}, 0});
        tq.push({{x,y},0});
        sd[p_to_s(0,0)] = 0;
        td[p_to_s(x,y)] = 0;
        while (!sq.empty() || !tq.empty()) {
            if (!sq.empty()) {
                pair<pair<int,int>, int> curr = sq.front();
                sq.pop();
                int steps = curr.second;
                int ux = curr.first.first;
                int uy = curr.first.second;
                for (int i = 0; i < 8; ++i) {
                    int vx = ux + dx[i];
                    int vy = uy + dy[i];
                    if ((vx == x) && (vy == y)) {
                        return steps+1;
                    }
                    string loc = p_to_s(vx, vy);
                    if (td.find(loc) != td.end()) {
                        return steps + 1 + td[loc];
                    }
                    if (sd.find(loc) != sd.end()) {
                        continue;
                    }
                    sd[loc] = steps + 1;
                    sq.push({{vx, vy}, steps+1});
                }
            }
            if (!tq.empty()) {
                pair<pair<int,int>, int> curr = tq.front();
                tq.pop();
                int steps = curr.second;
                int ux = curr.first.first;
                int uy = curr.first.second;
                for (int i = 0; i < 8; ++i) {
                    int vx = ux + dx[i];
                    int vy = uy + dy[i];
                    if ((vx == 0) && (vy == 0)) {
                        return steps+1;
                    }
                    string loc = p_to_s(vx, vy);
                    if (sd.find(loc) != sd.end()) {
                        return steps + 1 + sd[loc];
                    }
                    if (td.find(loc) != td.end()) {
                        continue;
                    }
                    td[loc] = steps + 1;
                    tq.push({{vx, vy}, steps+1});
                }
            }
        }
        return INT_MAX;
    }
};
