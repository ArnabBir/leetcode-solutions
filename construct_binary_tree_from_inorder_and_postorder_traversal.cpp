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
    
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder,
                            int l, int r, int l2, int r2) {
        if(l > r || l2 > r2)   return nullptr;
        int val = postorder[r2];
        TreeNode* root = new TreeNode(val);
        int m = -1;
        for(int i = l; i <= r; ++i) {
            if(inorder[i] == val) {
                m = i;
            }
        }
        int left = m-l;
        root->left = buildTreeUtil(inorder, postorder, l, m-1, l2, l2+left-1);
        root->right = buildTreeUtil(inorder, postorder, m+1, r, l2+left, r2-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTreeUtil(inorder, postorder, 0, n-1, 0, n-1);
    }
};
