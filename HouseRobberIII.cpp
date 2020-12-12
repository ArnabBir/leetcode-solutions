/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int robUtil(TreeNode* root, bool skip, unordered_map<TreeNode*, int> &dp) {
        if(root == NULL)    return 0;
        if(dp.find(root) == dp.end()) {
            dp[root] = robUtil(root->left, false, dp) + robUtil(root->right, false, dp);
        }
        if(skip) {
            return dp[root];
        }
        else {
            return max(dp[root], root->val + robUtil(root->left, true, dp) + robUtil(root->right, true, dp));
        }
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return robUtil(root, false, dp);
    }
};
