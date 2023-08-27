// Link: https://leetcode.com/problems/furthest-point-from-origin

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cl = 0;
        int cr = 0;
        int cd = 0;
        for (int i = 0; i < n; ++i) {
            if (moves[i] == 'L') {
                ++cl;
            } else if (moves[i] == 'R') {
                ++cr;
            } else {
                ++cd;
            }
        }
        return abs(cl - cr) + cd;
    }
};
