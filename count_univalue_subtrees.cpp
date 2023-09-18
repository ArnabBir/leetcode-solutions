// Link : https://leetcode.com/problems/count-univalue-subtrees/

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
    bool countUnivalSubtreesUtil(TreeNode* node, int& count) {
        if (node == nullptr) {
            return true;
        }
        bool lt = countUnivalSubtreesUtil(node->left, count);
        bool rt = countUnivalSubtreesUtil(node->right, count);
        if (lt && rt) {
            if (node->left != nullptr && node->left->val != node->val) {
                return false;
            }
            if (node->right != nullptr && node->right->val != node->val) {
                return false;
            }
            ++count;
            return true;
        }
        return false;
    }

public:
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        countUnivalSubtreesUtil(root, ans);
        return ans;
    }
};
