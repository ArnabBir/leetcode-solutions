class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if((i == m-1 && j == n-1) || (obstacleGrid[i][j] == 1)) continue;
                if(i < m-1 && j < n-1) {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
                else if(i < m-1) {
                    dp[i][j]  = dp[i+1][j];
                }
                else if(j < n-1) {
                    dp[i][j] = dp[i][j+1];
                }
            }
        }
        return (int)dp[0][0];
    }
};
