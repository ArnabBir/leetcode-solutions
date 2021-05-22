class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = nums[0];
        int max2 = INT_MIN;
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            max1 = max(max1, nums[i]);
        }
        int max1_count = 0;
        for(int i = 0; i < n; ++i) {
            if(max1 == nums[i]) ++max1_count;
        }
        if(max1_count > 1) {
            max2 = max1;
        }
        else {
            for(int i = 0; i < n; ++i) {
                if(nums[i] < max1) {
                    max2 = max(max2, nums[i]);
                }
            }
        }
        return (max1-1)*(max2-1);
    }
};
