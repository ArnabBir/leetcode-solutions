class STNode {

public:
    int val;
    int l;
    int r;
    STNode* left;
    STNode* right;
    
    STNode() {
        val = 0;
        l = INT_MIN;
        r = INT_MAX;
        left = nullptr;
        right = nullptr;
    }
};

class NumArray {

private:
    STNode* root;
public:
    
    void createSTree(STNode* root, vector<int>& nums, int l, int r) {
        if(!root)   return;
        root->l = l;
        root->r = r;
        if(l == r) {
            root->val = nums[l];
            return;
        }
        int m = l + ((r-l)>>1);
        root->left = new STNode();
        createSTree(root->left, nums, l, m);
        root->right = new STNode();
        createSTree(root->right, nums, m+1,r);
        int leftVal = (root->left) ? root->left->val : 0;
        int rightVal = (root->right) ? root->right->val : 0;
        root->val = leftVal + rightVal;
    }
    
    NumArray(vector<int>& nums) {
        root = new STNode();
        createSTree(root, nums,0,nums.size()-1);
    }
    
    int updateUtil(STNode* node, int idx, int val) {
        if(!node)   return 0;
        int delta = 0;
        if(node->l == idx && idx == node->r) {
            delta = val - node->val;
            node->val = val;
            return delta;
        }
        if(node->l > idx || idx > node->r) {
            return 0;
        }
        delta = updateUtil(node->left, idx, val) + updateUtil(node->right, idx, val); 
        node->val += delta;
        return delta;
    }
    
    void update(int index, int val) {
        STNode* node = root;
        updateUtil(node, index, val);
    }
    
    int sumRangeUtil(STNode* node, int left, int right) {
        if(!node) return 0;
        if(node->l >= left && node->r <= right) {
            return node->val;
        } 
        return sumRangeUtil(node->left, left, right) + sumRangeUtil(node->right, left, right);
    }
    
    int sumRange(int left, int right) {
        STNode* node = root;
        return sumRangeUtil(node, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
