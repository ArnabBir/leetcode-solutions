class Solution {
    
private:
    int ans = INT_MIN;
public:  
    int maxPathSumUtil(TreeNode* node, int sum) {
        if(!node)   return 0;
        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;
        int leftSum = max(0, maxPathSumUtil(leftNode, node->val + sum));
        int rightSum = max(0, maxPathSumUtil(rightNode, node->val + sum));
        ans = max(ans, leftSum + rightSum + node->val);
        return max(leftSum, rightSum) + node->val;
    }
    
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root, 0); 
        return ans;
    }
};
