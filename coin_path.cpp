// Link : https://leetcode.com/problems/coin-path/

class Solution {

    bool static compare_vectors(pair<int, vector<int> >& p1, pair<int, vector<int> >& p2) {
        int l1 = p1.first;
        int l2 = p2.first;
         if (l1 < l2) {
            return true;
        }
        if (l1 > l2) {
            return false;
        }
        vector<int> a = p1.second;
        vector<int> b = p2.second;
        int x = a.size();
        int y = b.size();
        int z = min(x, y);
        for (int i = 0; i < z; ++i) {
            if (a[i] == b[i]) {
                continue;
            }
            return a[i] < b[i];
        }
        return x < y;
    }

public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<pair<int, vector<int> > > dp(n, {-1, {}});
        dp[0] = {coins[0], {1}};
        for (int i = 0; i < n-1; ++i) {
            if (coins[i] == -1 || dp[i].first == -1) {
                continue;
            }
            for (int j = 1; j <= maxJump; ++j) {
                if (i + j >= n || coins[i + j] == -1) {
                    continue;
                }
                vector<int> path = dp[i].second;
                path.push_back(i + j + 1);
                pair<int, vector<int> > next = {dp[i].first + coins[i+j], path};
                if (dp[i+j].first == -1 || compare_vectors(next, dp[i+j])) {
                    dp[i+j] = next;
                }
            }
        }
        if (dp[n-1].first == -1) {
            return {};
        }
        return dp[n-1].second;
    }
};

class SolutionAlternate {

    long jump(vector<int>& dp,
              vector<int>& path,
              vector<int>& coins,
              int curr, int maxJump) {
        int n = coins.size();
        if (curr == n-1 && coins[curr] >= 0) {
            return coins[curr];
        }
        if (dp[curr] != -1) {
            return dp[curr];
        }
        int mincost = INT_MAX;
        for (int next = curr + 1; next <= curr + maxJump && next < n; ++next) {
            if (coins[next] == -1) {
                continue;
            }
            long cost = coins[curr] + jump(dp, path, coins, next, maxJump);
            if (cost < mincost) {
                mincost = cost;
                path[curr] = next;
            }
        }
        return dp[curr] = mincost;
    }

public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<int> dp(n, -1);
        vector<int> path(n, -1);
        jump(dp, path, coins, 0, maxJump);
        vector<int> ans;
        int i;
        for (i = 0; i < n && path[i] > 0; i = path[i]) {
            ans.push_back(i+1);
        }
        if (i == n-1 && coins[i] >= 0) {
            ans.push_back(i+1);
        }
        return ans;
    }
};
