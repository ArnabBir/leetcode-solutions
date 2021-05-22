class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_so_far(n);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; ++i) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                max_so_far[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            max_so_far[s.top()] = n-1;
            s.pop();
        }
        int j = 0;
        vector<int> result;
        for(int i = 0; i <= n-k; ++i) {
            while(j < i || max_so_far[j] < i+k-1) {
                ++j;
            }
            result.push_back(nums[j]);
        }
        return result;
        
        
    }
};
