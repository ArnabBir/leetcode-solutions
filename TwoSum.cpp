class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> revs;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            if(revs[target-nums[i]] != 0) {
                result.push_back(revs[target-nums[i]]-1);
                result.push_back(i);
                break;
            }
            revs[nums[i]] = i+1;
        }
        return result;
    }
};
