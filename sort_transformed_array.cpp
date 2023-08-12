// Link : https://leetcode.com/problems/sort-transformed-array

class Solution {
    int get_qudratic_value(int& x, int& a, int& b, int& c) {
        return a*x*x + b*x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] = get_qudratic_value(nums[i], a, b, c);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};