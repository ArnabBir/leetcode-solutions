// Link : https://leetcode.com/problems/next-permutation/submissions

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for (i = n-1; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                break;
            }
        }
        sort(nums.begin() + i, nums.end());
        if (i > 0) {
            for (int j = i; j < n; ++j) {
                if (nums[i-1] < nums[j]) {
                    swap(nums[i-1], nums[j]);
                    break;
                }
            }
        }
    }
};