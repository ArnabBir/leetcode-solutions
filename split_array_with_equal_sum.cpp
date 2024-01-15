// Link : https://leetcode.com/problems/split-array-with-equal-sum/

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 6) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            nums[i] = nums[i-1] + nums[i];
        }
        unordered_map<int, vector<int>> um;
        for (int i = 1; i < n-5; ++i) {
            int s1 = nums[i-1];
            for (int j = 3; j < n-3; ++j) {
                int s2 = nums[j-1] - nums[i];
                if (s1 == s2) {
                    um[s1].push_back(j);
                }
            }
        }
        for (int k = n-2; k >= 5; --k) {
            int s4 = nums[n-1] - nums[k];
            vector<int> js = um[s4];
            for (int j : js) {
                if (j + 1 >= k) {
                    continue;
                }
                int s3 = nums[k-1] - nums[j];
                if (s3 == s4) {
                    return true;
                }
            }
        }
        return false;
    }
};