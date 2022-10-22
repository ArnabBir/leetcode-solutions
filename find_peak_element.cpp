class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int h = nums.size()-1;
        if (h == 0) return 0;
        int l = 0;
        if(nums[0] > nums[1])   return 0;
        if(nums[h-1] < nums[h])   return h;
        while (l < h) {
            int m = l + ((h-l)>>1);
            if (nums[m] > nums[m-1] && nums[m] > nums[m+1]) {
               return m; 
            }
            if(nums[m] > nums[m+1]) {
                h = m;
            }
            else {
                l = m+1;
            }
        }
        return l;
    }
};
