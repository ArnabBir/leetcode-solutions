class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> um;
        int n = nums.size();
        vector<int> sums(n);
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(i == 0)  sums[i] = nums[i];
            else {
                sums[i] = sums[i-1] + nums[i];
            }
            if(sums[i] == k) {
                ++count;
            }
            um[sums[i]].push_back(i);
        }
        for(int i = 0; i < n; ++i) {
            if(um.find(sums[i]-k) != um.end()) {
                vector<int> v = um[sums[i]-k];
                for(int k = 0; k < v.size(); ++k) {
                    if(i > v[k]) ++count;
                }
            }
        }
        return count;
    }
};
