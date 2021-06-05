class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            ++um[nums[i]];
            if(um[nums[i]] > n/2) {
                return nums[i];
            }
        }
        return -1;
    }
};
