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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 1));
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int x = node->val;
            int d = q.front().second;
            q.pop();
            if(ans.size() < d) {
                ans.push_back(x);
            }
            if(node->right) {
                q.push(make_pair(node->right, d+1));
            }
            if(node->left) {
                q.push(make_pair(node->left, d+1));
            }
        }
        return ans;
    }
};
