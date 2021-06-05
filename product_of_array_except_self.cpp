class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int prod = 1;
        int n = nums.size();
        int zero = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i]) {
                prod *= nums[i];
            }
            else {
                ++zero;
            }
        }
        vector<int> result;
        for(int i = 0; i < n; ++i) {
            if(zero == 0) {
                result.push_back((int)(prod/nums[i]));
            }
            else if(zero == 1) {
                if(nums[i] == 0) {
                    result.push_back((int)(prod));
                }
                else {
                    result.push_back(0);
                }
            }
            else {
                result.push_back(0);
            }
        }
        return result;
    }
};
