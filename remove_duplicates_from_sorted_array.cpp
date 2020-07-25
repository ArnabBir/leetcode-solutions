class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int x = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[x] < nums[i]) {
                nums[x+1] = nums[i];
                ++x;
            }
        }
        return x+1;
    }
};
