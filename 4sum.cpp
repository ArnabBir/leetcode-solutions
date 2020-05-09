class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = n-1;
                while(k < l) {
                    long total = (long)(nums[i]) + (long)(nums[j]) + (long)(nums[k]) + (long)(nums[l]);
                    if(total == target) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        ans.push_back(temp);
                        do {
                            ++k;
                        }while(k < l && nums[k-1] == nums[k]);
                    }
                    else if(total < target) {
                        ++k;
                    }
                    else {
                        --l;
                    }
                }
            }
        }
        return ans;
    }
};
