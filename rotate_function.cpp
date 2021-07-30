lass Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int wsum = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            wsum += i*nums[i];
            sum += nums[i];
        }
        int ans = wsum;
        for(int i = 0; i < n-1; ++i) {
            wsum = wsum - sum + (n)*nums[i];
            ans = max(wsum, ans);
        }
        return ans;
    }
};
