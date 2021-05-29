class Solution {

private:
    vector<vector<int>> ans;
    vector<int> v;

public:
    
    void subsetsUtil(vector<int>& nums, int x, int n, vector<int>& v) {
        ans.push_back(v);
        for(int i = x; i < n; ++i) {
            v.push_back(nums[i]);
            subsetsUtil(nums, i+1, n, v);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        subsetsUtil(nums, 0, nums.size(), v);
        return ans;
    }
};
