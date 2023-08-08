// Link : https://leetcode.com/problems/factor-combinations

class Solution {
    void backtracking(vector<int>& factors, vector<vector<int>>& ans) {
        if (factors.size() > 1) {
            ans.push_back(factors);
        }
        int last = factors.back();
        factors.pop_back();
        for (int i = factors.empty() ? 2 : factors.back(); i <= last / i; ++i) {
            if (last % i == 0) {
                factors.push_back(i);
                factors.push_back(last/i);
                backtracking(factors, ans);
                factors.pop_back();
                factors.pop_back();
            }
        }
        factors.push_back(last);
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> factors;
        factors.push_back(n);
        backtracking(factors, ans);
        return ans;
    }
};