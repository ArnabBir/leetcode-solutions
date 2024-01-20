// Link : https://leetcode.com/problems/minimum-window-subsequence/

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int> > dp(n+1, vector<int> (m+1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i+1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int start = 0, len = n+1;
        for (int i = 1; i <= n; ++i) {
            if (dp[i][m] != 0) {
                int currlen = (i + 1) - dp[i][m];
                if (currlen < len) {
                    start = dp[i][m] -1;
                    len = currlen;
                }
            }
        }
        return len == n+1 ? "" : s1.substr(start, len);
    }
};
