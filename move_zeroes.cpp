class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        queue<int> id0;
        queue<int> idn0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                id0.push(nums[i]);          
            }
            else {
                idn0.push(nums[i]);
            }
        }
        int x = 0;
        while(!idn0.empty()) {
            nums[x++] = idn0.front();
            idn0.pop();
        }
        while(!id0.empty()) {
            nums[x++] = id0.front();
            id0.pop();
        }
    }
};
