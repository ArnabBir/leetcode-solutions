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
private:
    vector<int> sums;
public:
    
    void sumNumbersUtil(TreeNode* root, int sum) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            sums.push_back(sum*10+root->val);
            return;
        }
        sumNumbersUtil(root->left, sum*10+root->val);
        sumNumbersUtil(root->right, sum*10+root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        sumNumbersUtil(root, 0);
        return accumulate(sums.begin(), sums.end(), 0);
    }
};
