// Link : https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n = nums.size();
        long long int total = 0;
        for (int i = 0; i < n; ++i) {
            total += (long long int) nums[i];
        }
        if (total < (long long int) target) {
            return -1;
        }
        if (total == (long long int)target) {
            return 0;
        }
        vector<int> count(33,0);
        for (int i = 0; i < n; ++i) {
            ++count[log2(nums[i])];
        }
        int ans = 0;
        for (int i = 0; i < 32 && target > 0; ++i) {
            bool diff = false;
            if (target & (1<<i)) {
                if (count[i] > 0) {
                    --count[i];
                    target -= (1<<i);
                } else {
                    diff = true;
                }
            }
            count[i+1] += count[i]/2;
            count[i] = count[i]%2;
            for (int j = i+1; diff && j < 32; ++j) {
                if (count[j] > 0) {
                    ans += (j-i);
                    --count[j];
                    for (int k = i; k < j; ++k) {
                        ++count[k];
                    }
                    target -= (1<<i);
                    break;
                }
            }
        }
        
        return ans;
    }
};
