// Link : https://leetcode.com/problems/boundary-of-binary-tree/

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
    bool is_leaf(TreeNode* node) {
        return (node != nullptr) && (node->left == nullptr) && (node->right == nullptr);
    }

    void preorder(TreeNode* node, int b,
                  vector<int>& left,
                  vector<int>& right,
                  vector<int>& leaf) {
        if (node == nullptr) {
            return;
        }
        int l, r;
        if (b == 0) {
            l = 1;
            r = 2;
        } else if (b == 1) {
            l = 1;
            if (node->left == nullptr) {
                r = 1;
            } else {
                r = 3;
            }
        } else if (b == 2) {
            r = 2;
            if (node->right == nullptr) {
                l = 2;
            } else {
                l = 3;
            }
        } else {
            l = r = 3;
        }
        if (b == 0 || b == 1) {
            left.push_back(node->val);
        } else if (b == 2) {
            right.push_back(node->val);
        } else if (node->left == nullptr && node->right == nullptr) {
            leaf.push_back(node->val);
        }
        preorder(node->left, l, left, right, leaf);
        preorder(node->right, r, left, right, leaf);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        unordered_map<int, vector<int>> um;
        vector<int> left;
        vector<int> right;
        vector<int> leaves;
        vector<int> boundary;
        preorder(root, 0, left, right, leaves);
        reverse(right.begin(), right.end());
        boundary = left;
        for (int l : leaves) {
            boundary.push_back(l);
        }
        for (int l : right) {
            boundary.push_back(l);
        }
        return boundary;
    }
};