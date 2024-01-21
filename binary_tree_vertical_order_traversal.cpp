// Link : https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)  return {};
        unordered_map<int, vector<int> > um;
        queue<pair<int, TreeNode*> > q;
        q.push({0, root});
        int mind = 0;
        while (!q.empty()) {
            pair<int, TreeNode*> curr = q.front();
            q.pop();
            int d = curr.first;
            mind = min(mind, d);
            TreeNode* node = curr.second;
            um[d].push_back(node->val);
            if (node->left)     q.push({d-1, node->left});
            if (node->right)    q.push({d+1, node->right});
        }
        vector<vector<int> > ans;
        for (int i = mind; um[i].size() > 0; ++i) {
            ans.push_back(um[i]);
        }
        return ans;
    }
};
