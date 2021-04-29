class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return true;
        vector<bool> cr(n, false);
        cr[n-1] = true;
        for(int i = n-2; i >= 0; --i) {
            for(int j = i+1; j <= i + nums[i]; ++j) {
                if(cr[j]) {
                    cr[i] = true;
                    break;
                }
            }
        }
        return cr[0];
    }
};
