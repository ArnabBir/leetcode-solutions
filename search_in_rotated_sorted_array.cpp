class Solution {
public:
    
    int binarySearch(vector<int>& nums, int l, int r, int target) {
       while(l <= r) {
           int m = l + ((r-l)>>1);
           if(nums[m] == target) {
               return m;
           }
           if(nums[l] <= nums[m]) {
               if(nums[l] <= target && target <= nums[m]) {
                   r = m-1;
               }
               else {
                   l = m+1;
               }
           }
           else {
               if(nums[m] <= target && target <= nums[r]) {
                   l = m+1;
               }
               else {
                   r = m-1;
               }
           }
           
       }
       return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, 0, n-1, target); 
    }
    
};
