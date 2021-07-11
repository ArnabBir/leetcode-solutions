class Solution {
private:
    vector<vector<int>> dp;
public:
    
    Solution() {
        dp.resize(101,vector<int>(10001,-1));
    }
    
    int superEggDrop(int k, int n) {
        if(k == 1 || n <= 1) {
            dp[k][n] = n;
            return n;
        }
        if(dp[k][n] != -1) return dp[k][n];
        int l = 1;
        int r = n;
        int ans = INT_MAX;
        while(l <= r) {
            int m = l + ((r-l)>>1);
            int lower = superEggDrop(k-1,m-1);
            int higher = superEggDrop(k, n-m);
            if(lower < higher) {
                l = m+1;
            }
            else {
                r = m-1;
            }
            ans = min(ans, 1 + max(lower,higher));
        }
        dp[k][n] = ans;
        return ans;
    }
};
