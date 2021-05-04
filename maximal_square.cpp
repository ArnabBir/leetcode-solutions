class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        int max_so_far = 0;
        for(int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            max_so_far = max(max_so_far, dp[0][j]);
        }
        for(int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            max_so_far = max(max_so_far, dp[i][0]);
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    max_so_far = max(max_so_far, dp[i][j]);
                }
            }
        }
        return max_so_far * max_so_far;
    }
};
