// Link : https://leetcode.com/problems/optimal-account-balancing

class Solution {
    int backtrack(vector<int>& balances, int curr, int n) {
        while (curr < n && balances[curr] == 0) {
            ++curr;
        }
        if (curr == n) {
            return 0;
        }
        int cost = INT_MAX;
        for (int next = curr + 1; next < n; ++next) {
            if (balances[next] * balances[curr] >= 0) {
                continue;
            }
            balances[next] += balances[curr];
            cost = min(cost, 1 + backtrack(balances, curr+1, n));
            balances[next] -= balances[curr];
        }
        return cost;
    }

public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balancesmap;
        for (vector<int> transaction : transactions) {
            int from = transaction[0];
            int to = transaction[1];
            int amount = transaction[2];
            balancesmap[from] -= amount;
            balancesmap[to] += amount;
        }
        unordered_map<int, int> inverted;
        for (auto it : balancesmap) {
            if (it.second == 0) {
                continue;
            }
            ++inverted[it.second];
        }
        int same = 0;
        for (auto it : inverted) {
            int diff = it.first;
            if (it.second == 0) {
                continue;
            }
            if (inverted.find(-diff) != inverted.end()) {
                same += min(inverted[-diff], inverted[diff]);
                if (inverted[diff] >= inverted[-diff]) {
                    inverted[diff] -= inverted[-diff];
                    inverted[-diff] = 0;
                } else {
                    inverted[-diff] -= inverted[diff];
                    inverted[diff] = 0;
                }
            }
        }
        vector<int> balances;
        for (auto it : inverted) {
            for (int i = 0; i < it.second; ++i) {
                balances.push_back(it.first);
            }
        }
        return same + backtrack(balances, 0, balances.size());
    }
};