class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> pos;
        pos.push(-1);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                pos.push(i);
            }
            else if(s[i] == ')') {
                if(!pos.empty()) {
                    pos.pop();
                }
                if(!pos.empty()) {
                    ans = max(ans, i-pos.top());
                }
                else {
                    pos.push(i);
                }
            }
        }
        return ans;
    }
};
