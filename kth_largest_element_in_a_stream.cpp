class KthLargest {
private:
    int n;
    priority_queue<int, vector<int>, greater<int> > knums;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < k && i < nums.size(); ++i) {
            knums.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(knums.empty()) {
           knums.push(val);
           return val;
        }
        knums.push(val);
        if(knums.size() > n)    knums.pop();
        return knums.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
