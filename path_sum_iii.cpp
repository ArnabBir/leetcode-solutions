class Solution {
    
public:
    
    int pathSumUtil(TreeNode* root, int path, int targetSum) {
        if(!root) return 0;
        path += root->val;
        if(path == targetSum) {
            return 1 + pathSumUtil(root->left, path, targetSum) 
                + pathSumUtil(root->right, path, targetSum);
        }
        return pathSumUtil(root->left, path, targetSum) 
                + pathSumUtil(root->right, path, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSumUtil(root, 0, targetSum) 
            + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
