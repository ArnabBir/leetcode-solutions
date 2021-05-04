class Solution {

private:
    int count;
    
public:
    
    Solution() {
        count = 0;
    }
    
    void backtrack(vector<int>& nums, int idx, int n, int sum, int target) {
        if(idx == n) {
            if(sum == target) {
                ++count;
            }
            return;
        }
        backtrack(nums, idx+1, n, sum + nums[idx], target);
        backtrack(nums, idx+1, n, sum - nums[idx], target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        backtrack(nums, 0, n, 0, target);
        return count;
    }
};
