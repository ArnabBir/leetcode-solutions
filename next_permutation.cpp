class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)    return;
        if(n == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        int x = n-2;
        while(x >= 0) {
            if(nums[x] < nums[x+1]) {
                int miny = x+1;
                for(int y = x+1; y < n; ++y) {
                    if(nums[x] < nums[y]) {
                        if(nums[miny] > nums[y]) {
                            miny = y;
                        }
                    }
                }
                swap(nums[x], nums[miny]);
                break;
            }
            --x;
        }
        sort(nums.begin()+x+1, nums.end());
    }
};
