// Link : https://leetcode.com/problems/count-the-number-of-k-big-indices/

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        multiset<int> pq1;
        int n = nums.size();
        if (n < 2*k+1) {
            return 0;
        }
        vector<bool> larger(n, true);
        for (int i = 0; i < n; ++i) {
            if (pq1.size() < k) {
                pq1.insert(nums[i]);
                larger[i] = false;
                continue;
            } 
            int top = *pq1.rbegin();
            if (top < nums[i]) {
                continue;
            }
            larger[i] = false;
            pq1.insert(nums[i]);
            pq1.erase(pq1.find(top));
        }
        pq1.clear();
        for (int i = n-1; i >= 0; --i) {
            if (pq1.size() < k) {
                pq1.insert(nums[i]);
                larger[i] = false;
                continue;
            } 
            int top = *pq1.rbegin();
            if (top < nums[i]) {
                continue;
            }
            larger[i] = false;
            pq1.insert(nums[i]);
            pq1.erase(pq1.find(top));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (larger[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

