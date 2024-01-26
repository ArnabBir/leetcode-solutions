// Link : https://leetcode.com/problems/basic-calculator-ii/

class Solution {
private:
    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    bool is_op(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

public:
    int calculate(string s) {
        int n = s.size();
        stack<int> nums;
        string digit;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (is_digit(c)) {
                digit += c;
            }
            if (is_op(c) || i == n-1){
                int digint = stoi(digit);
                if (op == '+') {
                    nums.push(digint);
                } else if (op == '-') {
                    nums.push(-digint);
                } else if (op == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * digint);
                } else {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / digint);
                }
                digit = "";
                op = c;
            }
        }
        int ans = 0;
        while (!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }
        return ans;
    }
};
