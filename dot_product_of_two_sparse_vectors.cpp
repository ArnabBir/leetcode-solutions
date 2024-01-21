// Link : https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

class SparseVector {
private:
    vector<int> nums;

public:
    
    SparseVector(vector<int> &nums) {
        this->nums = nums;
    }

    int getAt(int pos) {
        return nums[pos];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        for (int i = 0; i < nums.size(); ++i) {
            product += nums[i] * vec.getAt(i);
        }
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
