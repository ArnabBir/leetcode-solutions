// Link : https://leetcode.com/problems/encode-string-with-shortest-length/

class Solution {
    string encode_once(vector<vector<string>>& dp, string s, int x) {
        string ans = s;
        int n = s.size();
        for (int l = 1; l < n; ++l) {
            int i = 0;
            string pattern = s.substr(0,l);
            while (i < n) {
                if (pattern != s.substr(i, l)) {
                    break;
                }
                i += l;
            }
            if (i == n) {
                string curr = to_string(n/l) + "[" + dp[x][x+l-1] + "]";
                if (curr.size() < ans.size()) {
                    ans = curr;
                }
            }
        }
        return ans;
    }

public:
    string encode(string s) {
        int n = s.size();
        int minlen = INT_MAX;
        string ans = s;
        vector<vector<string>> dp(n, vector<string>(n));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i+l <= n; ++i) {
                int j = i+l-1;
                string substring = s.substr(i, l);
                dp[i][j] = substring;
                if (l < 5) {
                    continue;
                }
                for (int k = i; k < j; ++k) {
                    if (dp[i][j] == "abbbabbbcabbbabbbc") {
                        cout<<dp[i][j]<<","<<dp[i][k]<<","<<dp[k+1][j]<<endl;
                    }
                    if (dp[i][j].size() > (dp[i][k] + dp[k+1][j]).size()) {
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                    }
                }
                string pattern = encode_once(dp, substring, i);
                if (dp[i][j].size() > pattern.size()) {
                    dp[i][j] = pattern;
                }
                //cout<<((pattern != substring) ? (pattern + "," + dp[i][j]) : " ");
            }
        }
        return dp[0][n-1];
    }
};
