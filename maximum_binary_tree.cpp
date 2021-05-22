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
    TreeNode* constructMaximumBinaryTreeUtil(vector<int>& nums, int l, int r) {
        if(l >= r) return nullptr;
        if(l+1 == r)    return new TreeNode(nums[l]);
        int val = distance(nums.begin(), max_element(nums.begin()+l, nums.begin()+r));
        TreeNode* node = new TreeNode(nums[val]);
        node->left = constructMaximumBinaryTreeUtil(nums, l, val);
        node->right = constructMaximumBinaryTreeUtil(nums, val+1, r);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return constructMaximumBinaryTreeUtil(nums, 0, n);
    }
};
