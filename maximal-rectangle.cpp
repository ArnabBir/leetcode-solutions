class Solution {
public:
    
    int maxHist(vector<int>& dp) {
            stack<int> s;
            int ma = 0;
            int mh = 0, a = 0;
            int x = 0;
            int m = dp.size();
            while(x < m) {
                if(s.empty() || dp[s.top()] <= dp[x]) {
                    s.push(x++);
                }
                else {
                    mh = dp[s.top()];
                    s.pop();
                    a = mh * x;
                    if(!s.empty()) {
                        a = mh * (x - s.top()-1);
                    }
                    ma = max(ma, a);
                }
            }
        return ma;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)  return 0;
        int m = matrix[0].size();
        if(n == 1 && m == 1)    return matrix[0][0]-'0';
        int ma = 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j] - '0';
        }
        ma =  maxHist(dp[0]);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[i][j] = dp[i-1][j] + matrix[i][j] - '0';
            }
            ma = max(ma, maxHist(dp[i]));
        }
        return ma;
    }
};
