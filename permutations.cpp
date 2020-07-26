class Solution {
public:
    
    void permuteUtil(vector<int>& nums,
                     vector<int>& perm,
                     vector<bool>& visited,
                     vector<vector<int>> & perms,
                     int n) {
        
        if(perm.size() == n) {
            perms.push_back(perm);
            return;
        } 
        for(int i = 0; i < n; ++i) {
            if(visited[i])  continue;
            perm.push_back(nums[i]);
            visited[i] = true;
            permuteUtil(nums, perm, visited, perms, n);
            perm.pop_back();
            visited[i] = false;
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        vector<int> perm;
        int n = nums.size();
        vector<bool> visited(n, false);
        permuteUtil(nums, perm, visited, perms, n);
        return perms;
    }
};
