// Link : https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (us.find(nums[i]) == us.end()) {
                us.insert(nums[i]);
            } else {
                us.erase(nums[i]);
            }
        }
        return vector<int>(us.begin(), us.end());
    }
};