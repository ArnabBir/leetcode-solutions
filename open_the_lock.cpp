// Link : https://leetcode.com/problems/open-the-lock

class Solution {
    string moveup(string s, int x) {
        return s.substr(0,x) + (char)((((s[x] - '0')+1)%10) + '0') + s.substr(x+1);
    }

    string movedown(string s, int x) {
        return s.substr(0,x) + (char)((((s[x] - '0')+9)%10) + '0') + s.substr(x+1);
    }

public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if (start == target) {
            return 0;
        }
        int n = deadends.size();
        queue<pair<string, int>> q;
        q.push({start, 0});
        unordered_set<string> visited;
        for (string de : deadends) {
            visited.insert(de);
        }
        if (visited.find(start) != visited.end()) {
            return -1;
        }
        visited.insert(start);
        while (!q.empty()) {
            string curr = q.front().first;
            int count = q.front().second;
            q.pop();
            string next;
            for (int i = 0; i < 4; ++i) {
                next = moveup(curr, i);
                if (next == target) {
                    return count + 1;
                }
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, count+1});
                    
                }
                next = movedown(curr, i);
                if (next == target) {
                    return count + 1;
                }
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, count+1});
                }
            }
        }
        return -1;
    }
};
