// Link : https://leetcode.com/problems/time-taken-to-cross-the-door/

class Solution {

    void move(unordered_map<int, int>& timestate,
                   vector<int>& answer,
                   queue<pair<int, int> >& q,
                   int t,
                   bool exit) {
        timestate[t] = exit;
        answer[q.front().first] = t;
        q.pop();
    }

public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        int t = arrival[0];
        vector<int> answer(n);
        unordered_map<int, int> timestate; 
        int i = 0;
        queue<pair<int, int>> enter, exit;
        while (i < n || !enter.empty() || !exit.empty()) {
            while (i < n && arrival[i] == t) {
                if (state[i] == 0) {
                    enter.push({i,t});
                } else if (state[i] == 1) {
                    exit.push({i, t});
                }
                ++i;
            }
            if (timestate.find(t-1) == timestate.end() 
            || timestate[t-1] == 1) {
                if (!enter.empty() && !exit.empty()) {
                    int entertime = enter.front().second;
                    int exittime = exit.front().second;
                    move(timestate, answer, exit, t, true);
                } else if (!enter.empty()) {
                    move(timestate, answer, enter, t, false);
                } else if (!exit.empty()) {
                    move(timestate, answer, exit, t, true);
                }
            } else {
                if (!enter.empty() && !exit.empty()) {
                    int entertime = enter.front().second;
                    int exittime = exit.front().second;
                    move(timestate, answer, enter, t, false);
                } else if (!enter.empty()) {
                    move(timestate, answer, enter, t, false);
                } else if (!exit.empty()) {
                    move(timestate, answer, exit, t, true);
                }
            }
            ++t;
        }
        return answer;
    }
};
