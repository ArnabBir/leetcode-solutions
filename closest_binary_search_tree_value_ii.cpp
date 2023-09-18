// Link : https://leetcode.com/problems/closest-binary-search-tree-value-ii/

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
    void calculateMax(TreeNode* root, queue<int>& q, double target, int k) {
        if (q.size() == k) {
            if (abs(root->val - target) > target - q.front()) {
                return;
            }
            q.pop();
        }
        q.push(root->val);
    }

    void closestKValuesHelper(TreeNode* root, queue<int>& q, double target, int k) {
        if (root == nullptr) {
            return;
        }
        closestKValuesHelper(root->left, q, target, k);
        calculateMax(root, q, target, k);
        closestKValuesHelper(root->right, q, target, k);
    }
 
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> q;
        closestKValuesHelper(root, q, target, k);
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
