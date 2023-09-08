// Link : https://leetcode.com/problems/delete-and-earn

class Solution {
    unordered_map<int, int> um;
    unordered_map<int, int> cache;

    int maxPoints(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return um[n];
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        int point = um[n];
        cache[n] = max(maxPoints(n-1), point + maxPoints(n-2));
        return cache[n];
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxn = 0;
        for (int i = 0; i < n; ++i) {
            um[nums[i]] += nums[i];
            maxn = max(maxn, nums[i]);
        }
        return maxPoints(maxn);
    }
};