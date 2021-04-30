class Solution {

private:
    int counter;
    vector<int> temp;

public:
    
    Solution() {
        counter = 0;
    }
    
    void merge(vector<int>& nums, int l, int r) {
        
        int m = l + ((r-l)>>1);
        int s1 = l;
        int s2 = m+1;
        int e1 = m;
        int e2 = r;
        while(s2 <= e2) {
            while(s1 <= e1 && !((long)nums[s1] > 2*(long)nums[s2])) {
                ++s1;
            }
            counter += e1 - s1 + 1;
            ++s2;
        }
        int i = l, j = m+1, k = l;
        while(i <= e1 && j <= e2) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }
        while(i <= e1) {
            temp[k++] = nums[i++];
        }
        while(j <= e2) {
            temp[k++] = nums[j++];
        }
        for(int x = l; x <= r; ++x) nums[x] = temp[x];
    }
    
    void mergesort(vector<int>& nums, int l, int r) {
        if(l >= r)   return;
        int m = l + ((r-l)>>1);
        mergesort(nums, l, m);
        mergesort(nums, m+1, r);
        merge(nums, l, r);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        temp.resize(n,0);
        mergesort(nums, 0, n-1);
        return counter;
    }
};
