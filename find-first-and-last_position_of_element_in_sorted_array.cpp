class Solution {
public:
    int searchRangeUtil(vector<int>& nums, int target, int l, int r) {
        if(l >= r)  return -1;
        int m = l + ((r-l)>>1);
        if(target > nums[m]) {
            return searchRangeUtil(nums, target, m+1, r);
        }
        else if(target < nums[m]) {
            return searchRangeUtil(nums, target, l, m);
        }
        else {
            return m;
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int idx = searchRangeUtil(nums, target, 0, n);
        if(idx == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {
            int r = idx;
            int l = idx;
            while(r+1 < n && nums[r+1] == target) {
                ++r;
            }
            while(l-1 >= 0 && nums[l-1] == target) {
                --l;
            }
            ans.push_back(l);
            ans.push_back(r);
        }
        return ans;
    }
};
