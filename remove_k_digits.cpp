// Link : https://leetcode.com/problems/remove-k-digits

class Solution {
    string removeInitialZeros(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') {
                return s.substr(i);
            }
        }
        return "0";
    }
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) {
            return "0";
        }
        stack<pair<char,int>> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty()) {
                if (num[i] != '0') {
                    s.push({num[i], 1});
                }
            } else {
                while (!s.empty() && s.top().first > num[i] && k > 0) {
                    pair<char,int> topelem = s.top();
                    s.pop();
                    if (topelem.second > 1) {
                        s.push({topelem.first, topelem.second - 1});
                    }
                    --k;
                }
                if (s.empty() || s.top().first != num[i]) {
                    s.push({num[i], 1});
                } else {
                    pair<char,int> topelem = s.top();
                    s.pop();
                    s.push({topelem.first, topelem.second + 1});
                }
            }
        }
        num = "";
        while (!s.empty()) {
            pair<char,int> topelem = s.top();
            s.pop();
            if (k > 0) {
                --k;
            } else {
                num.push_back(topelem.first);
            }
            if (topelem.second > 1) {
                s.push({topelem.first, topelem.second -1});
            }
        }
        reverse(num.begin(), num.end());
        return removeInitialZeros(num);
    }
};
