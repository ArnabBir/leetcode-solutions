class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> vec {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int d = 0;
        pair<int, int> p;
        for(int i = 0; i < instructions.length(); i++) {
            if(instructions[i] == 'G') {
                p.first += vec[d].first;
                p.second += vec[d].second;
            } else if(instructions[i] == 'L') {
                d--;
                if(d < 0) d = vec.size() - 1;
            } else if(instructions[i] == 'R') {
                d++;
                if(d >= vec.size()) d = vec.size() - d;
            }
        }
        if(p.first == 0 && p.second == 0) return true;
        else if(d > 0) return true;
        
        return false;
    }
};
