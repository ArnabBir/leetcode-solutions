class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(n,0)));
        dp[1][1][0] = nums[0];
        for (int i = 1; i < n-1; ++i) {
            dp[0][0][i] = max(dp[0][0][i-1], dp[0][1][i-1]);
            dp[0][1][i] = max(dp[0][1][i-1], dp[0][0][i-1] + nums[i]);
            dp[1][0][i] = max(dp[1][0][i-1], dp[1][1][i-1]);
            dp[1][1][i] = max(dp[1][1][i-1], dp[1][0][i-1] + nums[i]);
        }
         dp[1][0][n-1] = max(dp[1][0][n-2], dp[1][1][n-2]);
         dp[1][1][n-1] = max(dp[0][1][n-2], dp[0][0][n-2] + nums[n-1]);
        return max(dp[1][0][n-1], dp[1][1][n-1]);
    }
};
