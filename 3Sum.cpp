class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            vector<vector<int>> empty;
            return empty;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> results;
        int n = nums.size();
        vector<int> result(3);
        for(int i = 0; i < n-2; ++i) {
            int j = i+1;
            int k = n-1;
            while(j < k) {
                long sum = (long)nums[i] + (long)nums[j] + (long)nums[k];
                if(sum == 0) {
                    result[0] = nums[i];
                    result[1] = nums[j];
                    result[2] = nums[k];
                    results.insert(result);
                    ++j;
                }
                else if(sum < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
        }
        vector<vector<int>> ans(results.begin(), results.end());
        return ans;
    }
};
