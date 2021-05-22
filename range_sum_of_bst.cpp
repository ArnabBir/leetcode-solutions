class Solution {

private:
    int sum;
    
public:
    
    Solution() {
        sum = 0;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)   return 0;
        rangeSumBST(root->left, low, high);
        int data = root->val;
        if(data >= low && data <= high) {
            sum += data;
        }
        rangeSumBST(root->right, low, high);
        return sum;
    }
};
