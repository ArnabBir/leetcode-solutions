// Link : https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxsofar = nums[0];
        int minsofar = nums[0];
        int ans = maxsofar;
        for (int i = 1; i < (int)nums.size(); ++i) {
            int temp = max(nums[i], max(nums[i]*maxsofar, nums[i]*minsofar));
            minsofar = min(nums[i], min(nums[i]*maxsofar, nums[i]*minsofar));
            maxsofar = temp;
            ans = max(maxsofar, ans);
        }
        return ans;
    }
};