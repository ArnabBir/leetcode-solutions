// Link : https://leetcode.com/problems/robot-room-cleaner/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = { 0, 1, 0,-1};
    string get_loc_key(int x, int y) {
        return to_string(x) + ":" + to_string(y);
    }

    void go_back(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
 
    void cleanRoomHelper(Robot& robot, unordered_set<string>& visited, int x, int y, int d) {
        visited.insert(get_loc_key(x, y));
        //cout<<get_loc_key(x, y)<<endl;
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int d1 = (d+i)%4;
            int x1 = x + dx[d1];
            int y1 = y + dy[d1];
            string new_key = get_loc_key(x1, y1);
            if (visited.find(new_key) == visited.end() && robot.move()) {
                cleanRoomHelper(robot, visited, x1, y1, d1);
                go_back(robot);
            }
            robot.turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        cleanRoomHelper(robot, visited, 0, 0, 0);
    }
};