// Link : https://leetcode.com/problems/number-of-ships-in-a-rectangle/description/

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
    unordered_map<string, int> cache;

    string getKey(int lx, int ly, int rx, int ry) {
        return to_string(lx) + "-" + to_string(ly) + "-" + to_string(rx) + "-" + to_string(ry);
    }

    int countShipsUtil(Sea sea, int lx, int ly, int rx, int ry) {
        if (lx > rx || ly > ry) {
            return 0;
        }
        string key = getKey(lx, ly, rx, ry);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        bool hasShips = sea.hasShips({rx, ry}, {lx, ly});
        if (!hasShips) {
            return 0;
        }
        if (lx == rx && ly == ry) {
            return 1;
        }
        int mx = lx + (rx - lx)/2;
        int my = ly + (ry - ly)/2;
        if (lx == rx) {
            return countShipsUtil(sea, lx, ly, mx, my) + countShipsUtil(sea, lx, my+1, mx, ry);
        }
        if (ly == ry) {
            countShipsUtil(sea, mx+1, ly, rx, my) + countShipsUtil(sea, mx+1, my+1, rx, ry);
        }
        return countShipsUtil(sea, lx, ly, mx, my) + countShipsUtil(sea, lx, my+1, mx, ry)
            + countShipsUtil(sea, mx+1, ly, rx, my) + countShipsUtil(sea, mx+1, my+1, rx, ry);
    }
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int lx = bottomLeft[0];
        int ly = bottomLeft[1];
        int rx = topRight[0];
        int ry = topRight[1];
        string key = getKey(lx, ly, rx, ry);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        return countShipsUtil(sea, lx, ly, rx, ry);
    }
};
