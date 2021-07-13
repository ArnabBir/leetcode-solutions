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
    
    pair<bool,int> isBalancedUtil(TreeNode* root) {
        if(root == nullptr) return make_pair(true, 0);
        pair<bool,int> left = isBalancedUtil(root->left);
        pair<bool,int> right = isBalancedUtil(root->right);
        if(left.first && right.first && abs(left.second - right.second) < 2) {
            return make_pair(true, 1+max(left.second, right.second));
        }
        return make_pair(false, -1);
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedUtil(root).first;
    }
};
