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
    
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder,
                            int l1, int r1, int l2, int r2) {
        if(l1 > r1 || l2 > r2)  return nullptr;
        int val = preorder[l2];
        TreeNode* node = new TreeNode(val);
        int m = -1;
        for(int i = l1; i <= r1; ++i) {
            if(inorder[i] == val) {
                m = i;
                break;
            }
        }
        int left = m-l1;
        node->left = buildTreeUtil(preorder, inorder, l1, m-1, l2+1, l2+left);
        node->right = buildTreeUtil(preorder, inorder, m+1, r1, l2+left+1, r2);
        return node;
    }
     
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildTreeUtil(preorder, inorder, 0, n-1, 0, n-1);
    }
};
