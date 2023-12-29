// Link : https://leetcode.com/problems/closest-binary-search-tree-value/?source=submission-ac

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
    int closestValue(TreeNode* root, double target) {
        if (root == nullptr) {
            return INT_MAX;
        }
        int curr = root->val;
        int next = INT_MAX;
        if (curr == target) {
            return curr;
        } else if (target < curr) {
            next = closestValue(root->left, target);
        } else {
            next = closestValue(root->right, target);
        }
        if (abs(next - target) == abs(curr - target)) {
            return min(curr, next);
        }
        if (abs(next - target) < abs(curr - target)) {
            return next;
        }
        return curr;
    }
};