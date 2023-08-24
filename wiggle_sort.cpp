// Link : https://leetcode.com/problems/wiggle-sort

/*
3, 5, 2, 1, 6, 4
1, 2, 3, 4, 5, 6 =>  => 1, 6, 2, 4, 5, 3
1, 6, 2, 5, 3, 4

1, 2, 3, 4, 5, 6, 7
1, 7, 2, 6, 3, 4, 5 => 1, 7, 2, 6, 3, 5, 4
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int j = 0, k = n-1;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            if (i%2 == 0) {
                ans[i] = nums[j++];
            } else {
                ans[i] = nums[k--];
            }
        }
        if (n%2) {
            if (ans[n-2] < ans[n-1])
            swap(ans[n-2], ans[n-1]);
        }
        nums = ans;
    }
};