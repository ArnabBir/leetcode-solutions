class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)   return false;
        int m = sum/2;
        set<int> dp;
        for(int i = 0; i < n; ++i) {
            vector<int> v;
            for(auto & it : dp) {
                int x = it + nums[i];
                if(x > m)   break;
                v.push_back(x);
            }
            dp.insert(v.begin(), v.end());
            dp.insert(nums[i]);
            if(dp.find(m) != dp.end()) {
                return true;
            }
        }
        return false;
    }
};
