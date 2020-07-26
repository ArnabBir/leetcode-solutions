class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 1;
        vector<int> idx(n, 0);
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 1 || nums[i] > n) {
                nums[i] = -1;
            }
            else {
                idx[nums[i]-1] = 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(idx[i] == 0) {
                return i+1;
            }
        }
        return n+1;
    }
};
