class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int x = nums[i];
            if(s.find(x-1) != s.end()) {
                continue;
            }
            while(s.find(x) != s.end()) {
                ++x;
            }
            ans = max(ans, x-nums[i]);
        }
        return ans;
    }
};
